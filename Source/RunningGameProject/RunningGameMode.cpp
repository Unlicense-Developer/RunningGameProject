#include "RunningGameMode.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"

ARunningGameMode::ARunningGameMode()
{
    static ConstructorHelpers::FClassFinder<AMyPlayer> MyPlayerClass(TEXT("/Script/RunningGameProject.MyPlayer"));
    DefaultPawnClass = MyPlayerClass.Class;
    static ConstructorHelpers::FClassFinder<AMyPlayerController> MyPlayerControllerClass(TEXT("/Script/RunningGameProject.MyPlayerController"));
    PlayerControllerClass = MyPlayerControllerClass.Class;
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

void ARunningGameMode::StartGame()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Start Game")));
    UGameplayStatics::OpenLevel(this, FName(TEXT("TestLevel")));
}

void ARunningGameMode::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}

void ARunningGameMode::StartPlay()
{
    Super::StartPlay();

}