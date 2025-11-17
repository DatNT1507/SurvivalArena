// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/BTTask_Attack.h"

UBTTask_Attack::UBTTask_Attack()
{
	NodeName = TEXT("C++ Attack Task");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Attack Task Executed"));

	FTimerManager& TimerManager = AIController->GetWorld()->GetTimerManager();
	FTimerHandle TimerHandle;
	TimerManager.SetTimer(TimerHandle, [this, &OwnerComp]()
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}, AttackTime, false);

	return EBTNodeResult::InProgress;
}

FString UBTTask_Attack::GetStaticDescription() const
{
	return FString::Printf(TEXT("%s: %.1fs"), *Super::GetStaticDescription(), AttackTime);
}
