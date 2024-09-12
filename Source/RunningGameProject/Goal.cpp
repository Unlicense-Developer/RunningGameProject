// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SM_Portal.SM_Portal"));

	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
		StaticMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> Material(TEXT("/Game/DiscMaterial.DiscMaterial"));

	if (Material.Succeeded())
	{
		MaterialInst = Material.Object;
	}

	StaticMesh->SetMaterial(0, MaterialInst);
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGoal::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("Notify Actor Begin Overlap... Other Actor Name: %s"), *OtherActor->GetName()));
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

