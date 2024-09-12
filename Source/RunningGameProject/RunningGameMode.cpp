// Fill out your copyright notice in the Description page of Project Settings.


#include "RunningGameMode.h"
#include "MyPlayer.h"

ARunningGameMode::ARunningGameMode()
{
    static ConstructorHelpers::FClassFinder<AMyPlayer> MyPlayerClass(TEXT("/Script/RunningGameProject.MyPlayer"));
    DefaultPawnClass = MyPlayerClass.Class;
}

void ARunningGameMode::StartPlay()
{
    Super::StartPlay();

}
