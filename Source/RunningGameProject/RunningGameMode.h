// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RunningGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAMEPROJECT_API ARunningGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;
};
