// Fill out your copyright notice in the Description page of Project Settings.


#include "AVoidPlayerController.h"
#include "../Charactor/AVoidCamera.h"
#include "../Charactor/AVoidCharacter.h"
#include "../Charactor/CharacterLight.h"
#include "../Level/LevelDirector.h"
#include "../UI/AVoidHUD.h"

#include "Kismet/GameplayStatics.h"



#include "AVoidGameModeBase.h"





void AAVoidGameModeBase::StartPlay()
{
    Super::StartPlay();

    UWorld *World = GetWorld();
    PlayerController = Cast<AAVoidPlayerController>(UGameplayStatics::GetPlayerController(World, 0));
    HUD = Cast<AAVoidHUD>(PlayerController->GetHUD());
    Character = Cast<AAVoidCharacter>(PlayerController->GetCharacter());
    //Camera = Cast<AAVoidCamera>(UGameplayStatics::GetPlayerCameraManager(World, 0)->Camera);
    PlayerController->Initialize(this);

    Character->OnCharacterDeadDelegate.AddDynamic(this, &AAVoidGameModeBase::GameOver);
    Character->DisableInput(PlayerController);
}

void AAVoidGameModeBase::SetCamera(AAVoidCamera *camera)
{
     Camera = camera;
}

void AAVoidGameModeBase::SetLevelDirector(ALevelDirector *levelDirector)
{
    LevelDirector = levelDirector;
}

void AAVoidGameModeBase::SetCharacterLight(ACharacterLight *characterLight)
{
    CharacterLight = characterLight;
}

void AAVoidGameModeBase::StartGame()
{
    if(bInGame) return;

    HUD->Hide();

    Character->EnableInput(PlayerController);
    LevelDirector->Start();
    Character->RestartCharacter();
    CharacterLight->SetActorTickEnabled(true);
    PlayerController->PlayerCameraManager->SetViewTarget(Camera);

    bInGame = true;
}

void AAVoidGameModeBase::RestartGame()
{
    if(!bInGame) return;

    HUD->Hide();
    LevelDirector->ResetLevelDirector();
    LevelDirector->Start();
    Character->EnableInput(PlayerController);
    Character->RestartCharacter();
   // Camera->Restart();
    // Character->Restart();

    bInGame = true;

}

void AAVoidGameModeBase::GameOver()
{
    HUD->ShowGameOver();
    Character->DisableInput(PlayerController);
    LevelDirector->Stop();
}
