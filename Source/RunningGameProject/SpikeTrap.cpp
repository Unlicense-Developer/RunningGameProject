// Fill out your copyright notice in the Description page of Project Settings.


#include "SpikeTrap.h"

ASpikeTrap::ASpikeTrap()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeAsset(TEXT("/Game/SM_SpikeTrap.SM_SpikeTrap"));

	if (SpikeAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(SpikeAsset.Object);
		StaticMesh->SetCollisionProfileName(TEXT("Obstacle"));
	}
}

void ASpikeTrap::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

void ASpikeTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckMoveTime(DeltaTime);
}

void ASpikeTrap::CheckMoveTime(float DeltaTime)
{
	if (!IsReadyToMove)
	{
		MoveSpike();
		return;
	}

	MoveTime += DeltaTime;

	if (MoveTime >= 3.0f)
	{
		IsReadyToMove = false;
	}
}

void ASpikeTrap::MoveSpike()
{
	if (GetActorLocation().Z >= InitialLocation.Z + 90.0f || IsSetting )
	{
		IsSetting = true;

		if (GetActorLocation().Z <= InitialLocation.Z)
		{
			IsReadyToMove = true;
			IsSetting = false;
			MoveTime = 0.0f;
		}

		StaticMesh->AddLocalOffset(FVector(0.0f, 0.0f, -2.0f));
	}
	else
	{
		StaticMesh->AddLocalOffset(FVector(0.0f, 0.0f, 6.0f));
	}
}
