// Fill out your copyright notice in the Description page of Project Settings.

#include "Locomotion.h"


#include "CharacterLight.h"

// Sets default values
ACharacterLight::ACharacterLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Locomotion = CreateDefaultSubobject<ULocomotion>("Locomotion");

}

void ACharacterLight::SetTarget(FVector Location)
{
    TargetLocation = Location;
}

void ACharacterLight::MoveVertical(float val)
{
    Locomotion->MoveVertical(val);
}

void ACharacterLight::MoveHorizontal(float val)
{
    Locomotion->MoveHorizontal(val);
}

void ACharacterLight::Restart()
{

}

// Called when the game starts or when spawned
void ACharacterLight::BeginPlay()
{
	Super::BeginPlay();
    SetActorTickEnabled(false);
    SetTarget(GetActorLocation());
	
}

// Called every frame
void ACharacterLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    FVector loc = GetActorLocation();
    loc = FMath::VInterpTo(loc , TargetLocation , DeltaTime , Speed);
    TargetLocation -= FVector(1,0,0)* FrictionSpeed * DeltaTime;

    SetActorLocation(loc);

}

