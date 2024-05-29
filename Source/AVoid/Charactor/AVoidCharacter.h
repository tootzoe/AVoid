// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AVoidCharacter.generated.h"





UCLASS()
class AVOID_API AAVoidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAVoidCharacter();

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterDeadSignature);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterRestartSignature);

    UPROPERTY(BlueprintAssignable)
    FCharacterDeadSignature OnCharacterDeadDelegate;

    UPROPERTY(BlueprintAssignable)
    FCharacterRestartSignature OnCharacterRestartDelegate;

    void RestartCharacter();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void Tick(float DeltaTime) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly)
    class ULocomotion* Locomotion;

    UPROPERTY(EditDefaultsOnly)
    class UMechanics* Mechanics;
    UPROPERTY(EditDefaultsOnly)
    class UCapsuleComponent* DeathCapsuleComponent;


private:
    bool bIsThrowingLight;
    FVector InitialLocation;

    void StartThrow();
    void ReleaseThrow();
    void StopThrow();

    void LightVertical(float val);
    void LightHorizontal(float val);

    UPROPERTY(EditInstanceOnly)
    class ACharacterLight* LightActor;

    void MoveCharacter(const struct FInputActionValue& val);
    void MoveLight(const struct FInputActionValue& val);


    UFUNCTION()
    void Die(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
             class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void Hit(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
             int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



};
