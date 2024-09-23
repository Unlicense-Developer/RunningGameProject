// Fill out your copyright notice in the Description page of Project Settings.


#include "Cola.h"
#include "RunningGameState.h"

ACola::ACola()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Cola/Cola_can.Cola_can"));

	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
		StaticMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	}

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset(TEXT("/Game/Sounds/ItemGet.ItemGet"));
	AudioComponent->SetSound(SoundAsset.Object);
}

void ACola::NotifyActorBeginOverlap(AActor* Other)
{
	AGameStateBase* CurGameState = GetWorld()->GetGameState();
	if (Cast<ARunningGameState>(CurGameState))
	{
		Cast<ARunningGameState>(CurGameState)->AddScore();
		AudioComponent->Play();
		Destroy();
	}
}

void ACola::Rotate()
{
	AddActorWorldRotation(FRotator(0.0f, 3.0f, 0.0f));
}

void ACola::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate();
}
