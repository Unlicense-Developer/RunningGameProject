// Fill out your copyright notice in the Description page of Project Settings.


#include "BGMManager.h"

// Sets default values
ABGMManager::ABGMManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RandomBGMNum = -1;

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset(TEXT("/Game/Sounds/BGM_StartMenu.BGM_StartMenu"));
	BGMList.Add(SoundAsset.Object);
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset1(TEXT("/Game/Sounds/BGM_InGame1.BGM_InGame1"));
	BGMList.Add(SoundAsset1.Object);
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset2(TEXT("/Game/Sounds/BGM_InGame2.BGM_InGame2"));
	BGMList.Add(SoundAsset2.Object);
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset3(TEXT("/Game/Sounds/BGM_InGame3.BGM_InGame3"));
	BGMList.Add(SoundAsset3.Object);
	static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset4(TEXT("/Game/Sounds/BGM_InGame4.BGM_InGame4"));
	BGMList.Add(SoundAsset4.Object);
}

// Called when the game starts or when spawned
void ABGMManager::BeginPlay()
{
	Super::BeginPlay();
	PlayBgm();
}

void ABGMManager::PlayBgm()
{
	RandomBGMNum = rand() % 4 + 1;

	if (GetWorld()->GetName() == FString(TEXT("StartLevel")))
	{
		AudioComponent->SetSound(BGMList[0]);
		AudioComponent->Play();
	}
	else
	{
		AudioComponent->SetSound(BGMList[RandomBGMNum]);
		AudioComponent->Play();
	}
}

// Called every frame
void ABGMManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

