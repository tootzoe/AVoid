// Fill out your copyright notice in the Description page of Project Settings.



#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputSubsystems.h"

#include "AVoidGameModeBase.h"




#include "AVoidPlayerController.h"


void AAVoidPlayerController::Initialize(AAVoidGameModeBase *GameMode)
{

    //UE_LOG(LogTemp, Warning, TEXT("Setup up Start/Restart Input here......"));

    UInputAction *gameStartAct = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/Menu/IA_StartGame.IA_StartGame"));
    UInputAction *gameRestartAct = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/Menu/IA_RestartGame.IA_RestartGame"));

    UInputMappingContext *gameMenuMapCtx = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/Input/Menu/IMC_GameMenu.IMC_GameMenu"));

    if (!gameStartAct || !gameRestartAct  || !gameMenuMapCtx  ) {
           UE_LOG(LogTemp, Warning, TEXT(" Load Input Actions or InputMappingContext failed...."));
           return;
      }

    if (UEnhancedInputComponent *eic = CastChecked<UEnhancedInputComponent>(InputComponent)){
         eic->BindAction(gameStartAct , ETriggerEvent::Triggered , GameMode , &AAVoidGameModeBase::StartGame );

         eic->BindAction(gameRestartAct , ETriggerEvent::Triggered , GameMode , &AAVoidGameModeBase::RestartGame );
    }

    APlayerController *controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (controller)
     if (APlayerController *ap = Cast<APlayerController>(controller)){
          if(UEnhancedInputLocalPlayerSubsystem *subSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ap->GetLocalPlayer())){
              subSys->AddMappingContext(gameMenuMapCtx , 0);
          }

     }

}
