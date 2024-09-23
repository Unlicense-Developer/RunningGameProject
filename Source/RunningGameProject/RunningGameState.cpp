// Fill out your copyright notice in the Description page of Project Settings.


#include "RunningGameState.h"

ARunningGameState::ARunningGameState()
{
	Score = 0;
	IsGameEnd = false;
}

void ARunningGameState::AddScore()
{
	Score++;
}

void ARunningGameState::EndGame()
{
	IsGameEnd = true;
}

void ARunningGameState::GameEndSetting()
{
	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorTickEnabled(false);
}
