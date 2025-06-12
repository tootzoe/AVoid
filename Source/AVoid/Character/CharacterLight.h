// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterLight.generated.h"

UCLASS()
class AVOID_API ACharacterLight : public AActor
{
	GENERATED_BODY()

public:
	ACharacterLight();

	UFUNCTION(BlueprintCallable)
	void SetTarget(FVector Location);
	
	virtual void Tick(float DeltaTime) override;
	void MoveVertical(float Value);
	void MoveHorizontal(float Value);
	void Restart();

protected:
	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float FrictionSpeed;
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class ULocomotion* Locomotion;


private:
	FVector InitialPosition;
	FVector TargetLocation;
};
