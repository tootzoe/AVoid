// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "GameFramework/PlayerController.h"

#include "AVoidPlayerController.generated.h"

UCLASS()
class AVOID_API AAVoidPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere,  Category="TOOT")
    TObjectPtr<class UInputMappingContext> DefaultIMC;
    UPROPERTY(EditAnywhere,  Category="TOOT")
    TObjectPtr<class UInputAction> StartGameAct;
    UPROPERTY(EditAnywhere,  Category="TOOT")
    TObjectPtr<class UInputAction> RestartGameAct;


    virtual void InitInputSystem() override;


    // AActor interface
    protected:
   // virtual void BeginPlay() override;



    private:





    };



