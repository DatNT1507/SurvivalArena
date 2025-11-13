// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_EnemyController.h"

AAI_EnemyController::AAI_EnemyController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	
	ConfigureSight(SightConfig);

	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AAI_EnemyController::OnPerceptionUpdated);
}

void AAI_EnemyController::ConfigureSight(UAISenseConfig_Sight* SightConfig) const
{
	if (SightConfig)
	{
		SightConfig->SightRadius = 1500.0f;
		SightConfig->LoseSightRadius = 2000.0f;
		SightConfig->PeripheralVisionAngleDegrees = 90.0f;

		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = false;

		// Attach to Perception Component
		AIPerceptionComponent->ConfigureSense(*SightConfig);

		// Set (Sight) as a main sense
		AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
	}
}

void AAI_EnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AAI_Enemy* AIEnemy = Cast<AAI_Enemy>(InPawn);

	if (AIEnemy)
	{
		if (AIEnemy->GetBehaviorTree())
		{
			BlackboardComponent->InitializeBlackboard(*(AIEnemy->GetBehaviorTree()->GetBlackboardAsset()));

			RunBehaviorTree(AIEnemy->GetBehaviorTree());
		}
	}
}

void AAI_EnemyController::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (PlayerPawn == nullptr)
	{
		return;
	}

	for (AActor* Actor : UpdatedActors)
	{
		FActorPerceptionBlueprintInfo Info;
		AIPerceptionComponent->GetActorsPerception(Actor, Info);

		if (Actor == PlayerPawn)
		{
			for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
			{
				if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
				{
					if (Stimulus.WasSuccessfullySensed())
					{
						BlackboardComponent->SetValueAsObject("TargetPlayer", PlayerPawn);
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Player Spotted"));
						return;
					}
					else
					{
						BlackboardComponent->ClearValue("TargetPlayer");
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player Lost"));
						return;
					}
				}
			}
		}
	}
}
