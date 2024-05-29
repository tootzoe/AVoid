// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Character.h"

#include "AVoid/Utils/Debug.h"

#include "Locomotion.h"

// Sets default values for this component's properties
ULocomotion::ULocomotion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void ULocomotion::Initialize()
{

}

void ULocomotion::MoveVertical(float val)
{
    if(val == 0.f) return;

    InputVector += GetOwner()->GetActorUpVector() * val;
}

void ULocomotion::MoveHorizontal(float val)
{
    if(val == 0.f) return;

    InputVector += GetOwner()->GetActorRightVector() * val;
}


// Called when the game starts
void ULocomotion::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void ULocomotion::ApplyMovementFriction()
{
    FVector dire = MovementVector;
    dire.Normalize();
    MovementVector -= dire * MovementSpeed / FrictionRelation;
}


// Called every frame
void ULocomotion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    InputVector.Normalize();
    InputVector *= MaxMovementSpeed;
    MovementVector += InputVector;
    ApplyMovementFriction();

    DEBUG_LOG_TICK(MovementVector.ToString());
    GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + MovementVector * DeltaTime * MovementSpeed );

    InputVector = FVector(0);
}

