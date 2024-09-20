// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenuGameMode.h"
#include "BGMManager.h"

AStartMenuGameMode::AStartMenuGameMode()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> UserWidgetClass(TEXT("/Game/BP_StartMenuWidget"));
	StartingWidgetClass = UserWidgetClass.Class;
}

void AStartMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

    ChangeWidget(StartingWidgetClass);
	GetWorld()->SpawnActor<ABGMManager>();
}

void AStartMenuGameMode::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurWidget != nullptr)
    {
        CurWidget->RemoveFromViewport();
        CurWidget = nullptr;
    }

    if (NewWidgetClass != nullptr)
    {
        CurWidget = CreateWidget(GetWorld(), NewWidgetClass);

        if (CurWidget != nullptr)
        {
            CurWidget->AddToViewport();
        }
    }
}

void AStartMenuGameMode::StartGame()
{
    UGameplayStatics::OpenLevel(this, FName(TEXT("GameLevel")));
}

void AStartMenuGameMode::QuitGame()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, true);
}
