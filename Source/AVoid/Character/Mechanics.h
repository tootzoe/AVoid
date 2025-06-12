// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AVoidCharacter.h"
#include "Mechanics.generated.h"

UCLASS()
class AVOID_API UMechanics : public UActorComponent
{
	GENERATED_BODY()

public:
	void SetLight(ACharacterLight* Actor);
	
	void StopThrow();
	void Throw();
	void Recover();
	void LightHorizontal(float Value);
	void LightVertical(float Value);
	
protected:
	UPROPERTY(EditAnywhere)
	float CharacterLightOffset = 15.f;
	
	UPROPERTY(EditAnywhere)
	float ThrowDistance = 2000.f;
private:
	UPROPERTY(Transient)
	ACharacterLight* LightActor;


};
