// Fill out your copyright notice in the Description page of Project Settings.


#include "Cola.h"

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
}

void ACola::NotifyActorBeginOverlap(AActor* Other)
{
	Destroy();
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
