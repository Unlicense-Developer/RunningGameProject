// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster.h"

// Sets default values
AMonster::AMonster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(L"StaticMesh'/Game/Engine/BasicShapes/Cube.uasset'");
	if (CubeMesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(CubeMesh.Object);
	}

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMonster::Move()
{
	AddActorWorldOffset(GetActorForwardVector());
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

