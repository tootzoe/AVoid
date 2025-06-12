// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Locomotion.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AVOID_API ULocomotion : public UActorComponent
{
	GENERATED_BODY()

public:
	ULocomotion();

	void Initialize();
    void MoveVertical(float Value);
    void MoveHorizontal(float Value);
    void Move(const struct FInputActionValue& val);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 1.f;
	
	UPROPERTY(EditAnywhere)
	float MaxMovementSpeed = 2.f;
	
	UPROPERTY(EditAnywhere)
	float FrictionRelation = 1.f;

	UPROPERTY(EditAnywhere)
	float GravityForce = 9.81f;
	
	virtual void BeginPlay() override;

private:

	FVector ForceVector;
	FVector MovementVector;
	FVector InputVector;
	FVector TargetMovementVector;

	void ApplyMovementFriction();


};
