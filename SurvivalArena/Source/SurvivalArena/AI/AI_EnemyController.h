// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "AI_EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALARENA_API AAI_EnemyController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_EnemyController();	
	
protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* AIPerceptionComponent;
	
	void ConfigureSight(UAISenseConfig_Sight* SightConfig);
};
