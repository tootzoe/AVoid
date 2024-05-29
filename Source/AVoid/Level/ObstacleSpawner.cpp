// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"

#include "Kismet/KismetMathLibrary.h"


#include "ObstacleSpawner.h"

// Sets default values for this component's properties
UObstacleSpawner::UObstacleSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

TSubclassOf<AActor> UObstacleSpawner::GetRandomActorFromArray(TArray<TSubclassOf<AActor> > Actors)
{
    int Num = Actors.Num();
    int randNum = UKismetMathLibrary::RandomIntegerInRange(0 , Num - 1);
    return Actors[randNum];
}


// Called every frame
void UObstacleSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

AActor *UObstacleSpawner::SpawnObstacle()
{
    DifficultyCounter ++;

    TSubclassOf<AActor> ActorToSpawn;

    if(DifficultyCounter < 10){
        ActorToSpawn = GetRandomActorFromArray(EasyObstacle);
    }else     if(DifficultyCounter < 30){
        ActorToSpawn = GetRandomActorFromArray(MediumObstacle);
    }  else     {
        ActorToSpawn = GetRandomActorFromArray(HardObstacle);
    }

    FRotator Rotation = FRotator(0 , 0 , UKismetMathLibrary::RandomFloatInRange(0 , 360.f));
    AActor *Obstacle = GetWorld()->SpawnActor<AActor>(ActorToSpawn, FVector(7500 * 5, 0 ,0) , Rotation);
    return Obstacle;
}

