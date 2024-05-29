// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mechanics.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AVOID_API UMechanics : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMechanics();

    void SetLight(class ACharacterLight *Actor){LightActor = Actor;}
    void StopThrow();
    void Throw();
    void Recover();
    void LightVertical(float val);
    void LightHorizontal(float val);

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


    UPROPERTY(EditAnywhere)
    float CharacterLightOffset = 15.f;

    UPROPERTY(EditAnywhere)
    float ThrowDistance = 2000.f;


private:
    UPROPERTY(Transient)
    class ACharacterLight *LightActor;
		
};
