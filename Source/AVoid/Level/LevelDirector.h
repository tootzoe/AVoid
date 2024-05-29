// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "LevelDirector.generated.h"

UCLASS()
class AVOID_API ALevelDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelDirector();

    virtual void Tick(float DeltaTime) override;

    void Start();
    void Stop();
    void ResetLevelDirector();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    class USceneComponent *Root;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> ActorToSpawn;

    UPROPERTY(EditAnywhere)
    float SpawnTimer;
    UPROPERTY(EditAnywhere)
    float SpawnTimerDecreaseInSeconds = 0.1f;
    UPROPERTY(EditAnywhere)
    float SpawnPositionOffset;
    UPROPERTY(EditAnywhere)
    float Gravity;

    UPROPERTY(EditInstanceOnly)
    TArray<AActor*> AlreadyPlacedActors;

    UPROPERTY(EditAnywhere)
    class UObstacleSpawner *ObstacleSpawner;
private:
    FVector InitialLocation;
    FVector Location;
    FActorSpawnParameters SpawnParameters;
    FTimerHandle TimerHandle;
    TArray<AActor *> SpawnsArr;
    TArray<AActor *> ObstaclesArr;

    int ObstacleSpawnCounter;
    float InitialSpawnTimer;

    UFUNCTION()
    void SpawnWell();

    UFUNCTION()
    void SpawnObstacle();

    void RemoveSpawnHead();
    void AddAlreadySpawnedActors();


};
