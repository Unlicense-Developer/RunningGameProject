#include "RunningGameMode.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"
#include "RunningGameState.h"
#include "BGMManager.h"

ARunningGameMode::ARunningGameMode()
{
    static ConstructorHelpers::FClassFinder<AMyPlayer> MyPlayerClass(TEXT("/Script/RunningGameProject.MyPlayer"));
    DefaultPawnClass = MyPlayerClass.Class;
    static ConstructorHelpers::FClassFinder<AMyPlayerController> MyPlayerControllerClass(TEXT("/Script/RunningGameProject.MyPlayerController"));
    PlayerControllerClass = MyPlayerControllerClass.Class;
    static ConstructorHelpers::FClassFinder<ARunningGameState> MyGameStateClass(TEXT("/Script/RunningGameProject.RunningGameState"));
    GameStateClass = MyGameStateClass.Class;
    static ConstructorHelpers::FClassFinder<UUserWidget> UserWidgetClass(TEXT("/Game/BP_PlayerWidget"));
    StartingWidgetClass = UserWidgetClass.Class;
}

void ARunningGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
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

void ARunningGameMode::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);

    GetWorld()->SpawnActor<ABGMManager>();
}