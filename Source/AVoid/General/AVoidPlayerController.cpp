// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "AVoidGameModeBase.h"




// void AAVoidPlayerController::Initialize(AAVoidGameModeBase* GameMode)
// {
// 	InputComponent->BindAction("Start", IE_Pressed, GameMode, &AAVoidGameModeBase::StartGame);
// 	InputComponent->BindAction("Restart", IE_Pressed, GameMode, &AAVoidGameModeBase::RestartGame);
// }

void AAVoidPlayerController::InitInputSystem()
{
    Super::InitInputSystem();


    //
    checkf(DefaultIMC , TEXT("DefaultIMC invalid...."));
    checkf(StartGameAct , TEXT("StartGameAct invalid...."));
    checkf(RestartGameAct , TEXT("RestartGameAct invalid...."));




    UEnhancedInputComponent* tmpEIComp = Cast<UEnhancedInputComponent>(InputComponent);
    checkf( tmpEIComp, TEXT("Cast to UEnhancedInputComponent invalid...."));


    UEnhancedInputLocalPlayerSubsystem* einputSubsys = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

    checkf(einputSubsys , TEXT("einputSubsys invalid...."));

    einputSubsys->ClearAllMappings();

    einputSubsys->AddMappingContext(DefaultIMC, 0);

    AAVoidGameModeBase* tmpGM =  CastChecked <AAVoidGameModeBase>(   UGameplayStatics::GetGameMode (GetWorld()));


    tmpEIComp->BindAction(StartGameAct , ETriggerEvent::Started, tmpGM, &AAVoidGameModeBase::StartGame  );
    tmpEIComp->BindAction(RestartGameAct , ETriggerEvent::Started, tmpGM, &AAVoidGameModeBase::RestartGame  );

    //
   // bShowMouseCursor = true;

}


// void AAVoidPlayerController::BeginPlay()
// {
//     Super::BeginPlay();


//    // bShowMouseCursor = true;

// }

