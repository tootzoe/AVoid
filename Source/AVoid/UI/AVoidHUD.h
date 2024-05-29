// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AVoidHUD.generated.h"

/**
 * 
 */
UCLASS()
class AVOID_API AAVoidHUD : public AHUD
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent , BlueprintCallable)
    void ShowMenu();
    UFUNCTION(BlueprintImplementableEvent , BlueprintCallable)
    void ShowGameOver();
    UFUNCTION(BlueprintImplementableEvent , BlueprintCallable)
    void Hide();





	
};
