// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObstacleSpawner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AVOID_API UObstacleSpawner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObstacleSpawner();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


    int DifficultyCounter;

    AActor *SpawnObstacle();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<AActor> > EasyObstacle;
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<AActor> > MediumObstacle;
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<AActor> > HardObstacle;

private:
    TSubclassOf<AActor> GetRandomActorFromArray(TArray<TSubclassOf< AActor > > Actors);
		
};
