// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingFloor.h"

AMovingFloor::AMovingFloor()
{
	PrimaryActorTick.bCanEverTick = true;
	SpeedPower = 8.0f;
	MoveRange = 600.0f;
}

void AMovingFloor::BeginPlay()
{
	Super::BeginPlay();
	InitialPosition = GetActorLocation();
}

void AMovingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveType == EMovetype::E_LeftRight)
	{
		MoveLeftRight();
	}
	else if (MoveType == EMovetype::E_UpDown)
	{
		MoveUpDown();
	}
}

void AMovingFloor::MoveLeftRight()
{
	if (IsReverseDirection)
	{
		AddActorWorldOffset(FVector(0.0f, SpeedPower, 0.0f));
	}
	else
	{
		AddActorWorldOffset(FVector(0.0f, -SpeedPower, 0.0f));
	}

	if (GetActorLocation().Y >= InitialPosition.Y + MoveRange)
	{
		IsReverseDirection = false;
	}
	else if (GetActorLocation().Y <= InitialPosition.Y - MoveRange)
	{
		IsReverseDirection = true;
	}
}

void AMovingFloor::MoveUpDown()
{
	if (IsReverseDirection)
	{
		AddActorWorldOffset(FVector(0.0f, 0.0f, SpeedPower));
	}
	else
	{
		AddActorWorldOffset(FVector(0.0f, 0.0f, -SpeedPower));
	}

	if (GetActorLocation().Z >= InitialPosition.Z + MoveRange)
	{
		IsReverseDirection = false;
	}
	else if (GetActorLocation().Z <= InitialPosition.Z - MoveRange)
	{
		IsReverseDirection = true;
	}
}
