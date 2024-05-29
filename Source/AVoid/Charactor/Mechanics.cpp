// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterLight.h"





#include "Mechanics.h"

// Sets default values for this component's properties
UMechanics::UMechanics()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UMechanics::StopThrow()
{
    LightActor->SetTarget(LightActor->GetActorLocation());
}

void UMechanics::Throw()
{
     LightActor->SetTarget(LightActor->GetActorLocation() + FVector(ThrowDistance , 0 , 0));
}

void UMechanics::Recover()
{
    if(!LightActor) return;

    LightActor->SetTarget(GetOwner()->GetActorLocation() + FVector(CharacterLightOffset , 0,0));
}

void UMechanics::LightVertical(float val)
{
    LightActor->MoveVertical(val);
}

void UMechanics::LightHorizontal(float val)
{
    LightActor->MoveHorizontal(val);
}


// Called when the game starts
void UMechanics::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMechanics::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

