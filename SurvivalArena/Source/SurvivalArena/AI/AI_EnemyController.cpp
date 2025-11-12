// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_EnemyController.h"

AAI_EnemyController::AAI_EnemyController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	
	ConfigureSight(SightConfig);
}

void AAI_EnemyController::ConfigureSight(UAISenseConfig_Sight* SightConfig)
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
