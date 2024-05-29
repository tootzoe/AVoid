// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AVoidCamera.generated.h"

UCLASS()
class AVOID_API AAVoidCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAVoidCamera();

    virtual void Tick(float DeltaTime) override;

    void Restart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


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
    class AAVoidCharacter *Character;

    UPROPERTY()
    class USceneComponent *Root;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera" , meta = (AllowPrivateAccess = "true"))
    class UCameraComponent *FirstPersonCameraComponent;


private:
    FRotator RotationTowardsCharacter;


};
