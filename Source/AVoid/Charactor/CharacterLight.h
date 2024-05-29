// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterLight.generated.h"

UCLASS()
class AVOID_API ACharacterLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACharacterLight();

    UFUNCTION(BlueprintCallable)
    void SetTarget(FVector Location);

    void MoveVertical(float val);
    void MoveHorizontal(float val);
    void Restart();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




    UPROPERTY(EditAnywhere)
    float Speed;
    UPROPERTY(EditAnywhere)
    float FrictionSpeed;
    UPROPERTY(EditAnywhere)
    class ULocomotion* Locomotion;


private:
    FVector InitialPosition;
    FVector TargetLocation;


};
