// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelDirector.generated.h"

UCLASS()
class AVOID_API ALevelDirector : public AActor
{
	GENERATED_BODY()

public:
	ALevelDirector();

	virtual void Tick(float DeltaTime) override;

	void Start();
	void Stop();
	void ResetLevelDirector();

protected:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* Root;
	
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
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UObstacleSpawner* ObstacleSpawner;

private:
	FVector InitialLocation;
	FVector Location;
	FActorSpawnParameters SpawnParameters;
	FTimerHandle TimerHandle;
	TArray<AActor*> Spawns;
	TArray<AActor*> Obstacles;

	int ObstacleSpawnCounter;
	float InitialSpawnTimer;
	
	UFUNCTION()
	void SpawnWell();
	UFUNCTION()
	void SpawnObstacle();

	void RemoveSpawnHead();

	void AddAlreadySpawnedActors();
};
