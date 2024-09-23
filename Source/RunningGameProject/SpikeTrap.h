// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "SpikeTrap.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAMEPROJECT_API ASpikeTrap : public ABaseActor
{
	GENERATED_BODY()

public:
	ASpikeTrap();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void CheckMoveTime(float DeltaTime);

	void MoveSpike();

protected:
	float MoveTime;
	 
	bool IsReadyToMove = true;
	bool IsSetting = false;

	FVector InitialLocation;
};
