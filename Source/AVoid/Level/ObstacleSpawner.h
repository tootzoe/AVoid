// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObstacleSpawner.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AVOID_API UObstacleSpawner : public UActorComponent
{
	GENERATED_BODY()

public:
	UObstacleSpawner();

	int DifficultyCounter;

	AActor* SpawnObstacle();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> EasyObstacle;
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> MediumObstacle;
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> HardObstacle;
	
	virtual void BeginPlay() override;

private:
	TSubclassOf<AActor> GetRandomActorFromArray(TArray<TSubclassOf<AActor>> Actors);

};
