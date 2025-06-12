// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AVoidCamera.generated.h"

UCLASS()
class AVOID_API AAVoidCamera : public AActor
{
	GENERATED_BODY()

public:
	AAVoidCamera();

	virtual void Tick(float DeltaTime) override;
	void Restart();

protected:
	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	UPROPERTY(EditAnywhere)
	float MovementSpeed;

	UPROPERTY(EditAnywhere)
	float MaxDistance = 700.f;

	UPROPERTY(EditAnywhere)
	float FrictionSpeed = 10.f;

	UPROPERTY(EditAnywhere)
	FVector CharacterOffset;
	
	UPROPERTY(EditAnywhere)
	class AAVoidCharacter* Character;
	
	UPROPERTY()
	class USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;
	
	virtual void BeginPlay() override;

private:
	FRotator RotationTowardsCharacter;
};
