// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "RunningGameState.h"
#include "MyPlayer.h"

// Sets default values
AGoal::AGoal()
{
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
	if (Cast<AMyPlayer>(OtherActor))
	{
		Cast<ARunningGameState>(GetWorld()->GetGameState())->EndGame();
	}
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

