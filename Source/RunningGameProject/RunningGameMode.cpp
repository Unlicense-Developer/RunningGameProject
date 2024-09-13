#include "RunningGameMode.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"

ARunningGameMode::ARunningGameMode()
{
    static ConstructorHelpers::FClassFinder<AMyPlayer> MyPlayerClass(TEXT("/Script/RunningGameProject.MyPlayer"));
    DefaultPawnClass = MyPlayerClass.Class;
    static ConstructorHelpers::FClassFinder<AMyPlayerController> MyPlayerControllerClass(TEXT("/Script/RunningGameProject.MyPlayerController"));
    PlayerControllerClass = MyPlayerControllerClass.Class;

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
    //ChangeMenuWidget(StartingWidgetClass);
}

void ARunningGameMode::StartPlay()
{
    Super::StartPlay();

}