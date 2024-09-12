// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FloorAsset(TEXT("/Game/SM_FloorMesh.SM_FloorMesh"));

	if (FloorAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(FloorAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> WoodFloorMaterial(TEXT("/Game/Megascans/Surfaces/Wooden_Floor_wdipfjw/MI_Wooden_Floor_wdipfjw_2K.MI_Wooden_Floor_wdipfjw_2K"));

	if (WoodFloorMaterial.Succeeded())
	{
		MaterialInst = WoodFloorMaterial.Object;
	}

	StaticMesh->SetMaterial(0, MaterialInst);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

