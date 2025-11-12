// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/HealthComponent.h"
#include "Logging/LogMacros.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "SurvivalArenaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class ASurvivalArenaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
protected:

	/** Jump to Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* ShootAction;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	float ShotDamage = 25.f;

	// 3. Thêm Tầm bắn
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	float TraceDistance = 10000.f;

	// 4. Thêm công tắc bật/tắt debug
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	bool bDrawDebugTrace = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionStimuliSourceComponent* StimuliSourceComponent;
public:

	/** Constructor */
	ASurvivalArenaCharacter();	

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	void StartShoot();

	void PerformLineTrace() const;

	// Get start point and end point
	bool GetShotTracePoints(FVector& OutStartLocation, FVector& OutEndLocation) const;

	// The result of shoot (Hit or not)
	bool TraceForHit(const FVector& Start, const FVector& End, FHitResult& OutHit) const;

	// Logic after hit (Damage)
	void ProcessTraceHit(const FHitResult& HitResult) const;

	// Debug shooting
	void DrawTraceDebug(const FVector& Start, const FVector& End, const FHitResult& HitResult, bool bDidHit) const;
public:

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

	UFUNCTION(BlueprintPure, Category="Input")
	UHealthComponent* GetHealthComponent() const { return HealthComponent; }
public:

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

