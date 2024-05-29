// Fill out your copyright notice in the Description page of Project Settings.



#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "ObstacleSpawner.h"

#include "AVoid/Utils/Debug.h"


#include "LevelDirector.h"

PRAGMA_DISABLE_OPTIMIZATION



// Sets default values
ALevelDirector::ALevelDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>("Root");
    ObstacleSpawner = CreateDefaultSubobject<UObstacleSpawner>("ObstacleSpawner");

    RootComponent = Root;

}

// Called when the game starts or when spawned
void ALevelDirector::BeginPlay()
{
	Super::BeginPlay();

    InitialLocation = Root->GetComponentLocation() ; // + FVector(SpawnPositionOffset, 0,0);
    Location = InitialLocation;

    AddAlreadySpawnedActors();

    Stop();

    InitialSpawnTimer = SpawnTimer;

}

void ALevelDirector::SpawnWell()
{
    FRotator Rotation = FRotator(0, 0, UKismetMathLibrary::RandomFloatInRange(0, 360));
    AActor *Actor = GetWorld()->SpawnActor<AActor>(ActorToSpawn , InitialLocation + FVector(SpawnPositionOffset * 3 , 0 , 0),
                                                   Rotation, SpawnParameters);
    Actor->AttachToComponent(Root , FAttachmentTransformRules::KeepWorldTransform);
    SpawnsArr.Add(Actor);
    if(SpawnsArr.Num() > 5){
        RemoveSpawnHead();
    }
}

void ALevelDirector::SpawnObstacle()
{
    SpawnTimer -= SpawnTimerDecreaseInSeconds;
    if(SpawnTimer < 2.f){
        //Win ? State ? X d
        SpawnTimer = 2.f;
    }

    GetWorld()->GetTimerManager().SetTimer(TimerHandle , this, &ALevelDirector::SpawnObstacle , SpawnTimer);
    AActor *o = ObstacleSpawner->SpawnObstacle();
    o->AttachToComponent(Root , FAttachmentTransformRules::KeepWorldTransform);
    ObstaclesArr.Add(o);

}

void ALevelDirector::RemoveSpawnHead()
{
    if(SpawnsArr.Num() == 0 ) return;
    AActor *a = SpawnsArr[0];
    SpawnsArr.Remove(a);
    if(!a) return;

    a->Destroy();
}

void ALevelDirector::AddAlreadySpawnedActors()
{
    for(AActor *a : AlreadyPlacedActors){
        SpawnsArr.Add(a);
    }

}

// Called every frame
void ALevelDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelDirector::Start()
{
    SetActorTickEnabled(true);
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALevelDirector::SpawnObstacle, SpawnTimer);
}

void ALevelDirector::Stop()
{
    GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void ALevelDirector::ResetLevelDirector()
{
    Super::Reset();
    Root->SetWorldLocation(InitialLocation);

    while(SpawnsArr.Num() > 0){
        RemoveSpawnHead();
    }

    for(AActor *o  : ObstaclesArr){
        if(o && IsValid(o))
            o->Destroy();
    }

    SpawnsArr.Empty();
    ObstaclesArr.Empty();

    ObstacleSpawnCounter = 0;
    ObstacleSpawner->DifficultyCounter = 0;
    SpawnTimer = InitialSpawnTimer;

}


PRAGMA_ENABLE_OPTIMIZATION
