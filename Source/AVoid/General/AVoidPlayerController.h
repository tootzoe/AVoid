// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AVoidPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AVOID_API AAVoidPlayerController : public APlayerController
{
	GENERATED_BODY()

  public:
   void Initialize(class AAVoidGameModeBase*);
	
};
