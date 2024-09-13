// Fill out your copyright notice in the Description page of Project Settings.


#include "WindmillTrab.h"

AWindmillTrab::AWindmillTrab()
{
	SpeedPower = 2.0f;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SM_SM_WindmillTrab.SM_SM_WindmillTrab"));

	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
		StaticMesh->SetCollisionProfileName(TEXT("Obstacle"));
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> WoodFloorMaterial(TEXT("/Game/Megascans/Surfaces/Wooden_Floor_wdipfjw/MI_Wooden_Floor_wdipfjw_2K.MI_Wooden_Floor_wdipfjw_2K"));

	if (WoodFloorMaterial.Succeeded())
	{
		MaterialInst = WoodFloorMaterial.Object;
	}

	StaticMesh->SetMaterial(0, MaterialInst);
}

void AWindmillTrab::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldRotation(FRotator(0.0f, SpeedPower, 0.0f));
}
