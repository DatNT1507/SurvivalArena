// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AI/AI_Enemy.h"

AAI_EnemyController::AAI_EnemyController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	
	ConfigureSight(SightConfig);
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
