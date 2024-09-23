// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RunningGameState.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAMEPROJECT_API ARunningGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ARunningGameState();

	void AddScore();

	void EndGame();

	UFUNCTION(BlueprintCallable)
	void GameEndSetting();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Score;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsGameEnd;
};
