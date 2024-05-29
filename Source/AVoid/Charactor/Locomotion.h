// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Locomotion.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AVOID_API ULocomotion : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULocomotion();

    void Initialize();
    void MoveVertical( float val);
    void MoveHorizontal( float val);

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere)
    float MovementSpeed = 1.f;
    UPROPERTY(EditAnywhere)
    float MaxMovementSpeed = 2.f;
    UPROPERTY(EditAnywhere)
    float FrictionRelation = 1.f;
    UPROPERTY(EditAnywhere)
    float GravityForce = 9.81f;



private:
    FVector ForceVector;
    FVector MovementVector;
    FVector InputVector;
    FVector TargetMovementVector;

    void ApplyMovementFriction();
		
};








