// Copyright Epic Games, Inc. All Rights Reserved.

#include "AVoidGameModeBase.h"



#include "AVoidPlayerController.h"
#include "AVoid/Character/AVoidCamera.h"
#include "AVoid/Character/AVoidCharacter.h"
#include "AVoid/Character/CharacterLight.h"
#include "AVoid/Level/LevelDirector.h"
#include "AVoid/UI/AVoidHUD.h"
#include "Kismet/GameplayStatics.h"

void AAVoidGameModeBase::StartPlay()
{
	Super::StartPlay();

	UWorld* World = GetWorld();
	PlayerController = Cast<AAVoidPlayerController>(UGameplayStatics::GetPlayerController(World, 0)); 
	HUD = Cast<AAVoidHUD>(PlayerController->GetHUD());
	Character = Cast<AAVoidCharacter>(PlayerController->GetCharacter());
	//Camera = Cast<AAVoidCamera>(UGameplayStatics::GetPlayerCameraManager(World, 0)->Camera);
    // PlayerController->Initialize(this);

	Character->OnCharacterDeadDelegate.AddDynamic(this, &AAVoidGameModeBase::GameOver);
    Character->DisableInput(PlayerController);




}

void AAVoidGameModeBase::SetCamera(AAVoidCamera* camera)
{
	this->Camera = camera;
}

void AAVoidGameModeBase::SetLevelDirector(ALevelDirector* levelDirector)
{
	this->LevelDirector = levelDirector;
}

void AAVoidGameModeBase::SetCharacterLight(ACharacterLight* characterLight)
{
	this->CharacterLight = characterLight;
}

void AAVoidGameModeBase::StartGame()
{
	if(bInGame) return;
	
	HUD->Hide();
	Character->EnableInput(PlayerController);
	LevelDirector->Start();
	CharacterLight->SetActorTickEnabled(true);
	bInGame = true;
	PlayerController->PlayerCameraManager->SetViewTarget(Camera);
}

void AAVoidGameModeBase::RestartGame()
{
	if(!bInGame) return;

	HUD->Hide();
	LevelDirector->ResetLevelDirector();
	LevelDirector->Start();
	Character->EnableInput(PlayerController);
	Character->RestartCharacter();
	//Camera->Restart();
	//CharacterLight->Restart();
	bInGame = true;
}

void AAVoidGameModeBase::GameOver()
{
	HUD->ShowGameOver();
	Character->DisableInput(PlayerController);
	LevelDirector->Stop();
}
