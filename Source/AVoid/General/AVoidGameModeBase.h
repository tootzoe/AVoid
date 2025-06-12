// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AVoidGameModeBase.generated.h"

class AAVoidCamera;
class ALevelDirector;
class ACharacterLight;

UCLASS()
class AVOID_API AAVoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetCamera(AAVoidCamera* camera);

	UFUNCTION(BlueprintCallable)
	void SetLevelDirector(ALevelDirector* levelDirector);

	UFUNCTION(BlueprintCallable)
	void SetCharacterLight(ACharacterLight* characterLight);
	
	void StartGame();
	void RestartGame();
	
private:
	UPROPERTY(Transient)
	class AAVoidHUD* HUD;
	UPROPERTY(Transient)
	class AAVoidCharacter* Character;
	UPROPERTY(Transient)
	AAVoidCamera* Camera;
	UPROPERTY(Transient)
	class AAVoidPlayerController* PlayerController;
	UPROPERTY(Transient)
	ALevelDirector* LevelDirector;
	UPROPERTY(Transient)
	ACharacterLight* CharacterLight;
	
	bool bInGame;

	UFUNCTION()
	void GameOver();
};
