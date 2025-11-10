// Copyright Epic Games, Inc. All Rights Reserved.

#include "SurvivalArenaCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "SurvivalArena.h"

ASurvivalArenaCharacter::ASurvivalArenaCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ASurvivalArenaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASurvivalArenaCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ASurvivalArenaCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASurvivalArenaCharacter::Look);

		// Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &ASurvivalArenaCharacter::StartShoot);
	}
	else
	{
		UE_LOG(LogSurvivalArena, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ASurvivalArenaCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void ASurvivalArenaCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void ASurvivalArenaCharacter::StartShoot()
{
	PerformLineTrace();
}

void ASurvivalArenaCharacter::PerformLineTrace() const
{
	// Get start point and end point
	FVector TraceStart, TraceEnd;
	if (!GetShotTracePoints(TraceStart, TraceEnd))
	{
		return; 
	}

	// The rsult of shoot (Hit or not)
	FHitResult HitResult;
	bool bDidHit = TraceForHit(TraceStart, TraceEnd, HitResult);
	if (bDidHit)
	{
		ProcessTraceHit(HitResult);
	}

	// Debug shooting
	if (bDrawDebugTrace)
	{
		DrawTraceDebug(TraceStart, TraceEnd, HitResult, bDidHit);
	}
}

bool ASurvivalArenaCharacter::GetShotTracePoints(FVector& OutStartLocation, FVector& OutEndLocation) const
{
	if (FollowCamera == nullptr)
	{
		return false;
	}

	OutStartLocation = FollowCamera->GetComponentLocation();
	const FVector ForwardVector = FollowCamera->GetForwardVector();
	OutEndLocation = OutStartLocation + (ForwardVector * TraceDistance);
	
	return true;
}

bool ASurvivalArenaCharacter::TraceForHit(const FVector& Start, const FVector& End, FHitResult& OutHit) const
{
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this); 

	return GetWorld()->LineTraceSingleByChannel(
		OutHit,
		Start,
		End,
		ECC_Visibility,
		QueryParams
	);
}

void ASurvivalArenaCharacter::ProcessTraceHit(const FHitResult& HitResult) const
{
	AActor* HitActor = HitResult.GetActor();
	if (HitActor == nullptr)
	{
		return;
	}

	// Tìm HealthComponent trên Actor trúng đạn
	if (UHealthComponent* TargetHealthComp = HitActor->FindComponentByClass<UHealthComponent>())
	{
		// Gây sát thương bằng biến UPROPERTY
		TargetHealthComp->TakeDamage(ShotDamage);
	}
}

void ASurvivalArenaCharacter::DrawTraceDebug(const FVector& Start, const FVector& End, const FHitResult& HitResult, bool bDidHit) const
{
	// Draw Green if shoot an object, else red
	FColor DebugColor = bDidHit ? FColor::Green : FColor::Red;
	DrawDebugLine(GetWorld(), Start, End, DebugColor, false, 5.0f, 0, 1.0f);

	if (bDidHit)
	{
		// Print object name received bullet
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Hit: %s"), *HitResult.GetActor()->GetName()));
	}
}

void ASurvivalArenaCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void ASurvivalArenaCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ASurvivalArenaCharacter::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void ASurvivalArenaCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}
