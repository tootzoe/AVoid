// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterLight.h"
#include "Locomotion.h"
#include "Mechanics.h"

#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"



#include "AVoid/Utils/Debug.h"


#include "AVoidCharacter.h"

// Sets default values
AAVoidCharacter::AAVoidCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Locomotion = CreateDefaultSubobject<ULocomotion>("Locomotion");
    Mechanics = CreateDefaultSubobject<UMechanics>("Mechanics");
    DeathCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("SecondaryCapsuleComponent");

    DeathCapsuleComponent->SetupAttachment(RootComponent);


}

void AAVoidCharacter::RestartCharacter()
{
    SetActorLocation(InitialLocation);
    Mechanics->Recover();
    OnCharacterRestartDelegate.Broadcast();
}

// Called when the game starts or when spawned
void AAVoidCharacter::BeginPlay()
{
	Super::BeginPlay();

    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AAVoidCharacter::Hit);
    DeathCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AAVoidCharacter::Die);

    Mechanics->SetLight(LightActor);
    Mechanics->Recover();

    InitialLocation = GetActorLocation();

}

void AAVoidCharacter::StartThrow()
{

   // UE_LOG(LogTemp, Warning, TEXT("StartThrow...."));

    bIsThrowingLight  = true;
    Mechanics->Recover();
}

void AAVoidCharacter::ReleaseThrow()
{
   //  UE_LOG(LogTemp, Warning, TEXT("ReleaseThrow...."));
    if(bIsThrowingLight){
        bIsThrowingLight = false;
        Mechanics->Throw();
    }
}

void AAVoidCharacter::StopThrow()
{
    // UE_LOG(LogTemp, Warning, TEXT("StopThrow...."));
    if(bIsThrowingLight){
        bIsThrowingLight = false;
        Mechanics->StopThrow();
    }
}

void AAVoidCharacter::LightVertical(float val)
{
    if(!bIsThrowingLight) return;

    Mechanics->LightVertical(val);
}

void AAVoidCharacter::LightHorizontal(float val)
{
    if(!bIsThrowingLight) return;


    Mechanics->LightHorizontal(val);
}

void AAVoidCharacter::MoveCharacter(const FInputActionValue &val)
{
    const FVector2D val2D = val.Get<FVector2D>();

    if(!Locomotion) return;

    Locomotion->MoveVertical(val2D.Y);
    Locomotion->MoveHorizontal(val2D.X);

}

void AAVoidCharacter::MoveLight(const FInputActionValue &val)
{
    const FVector2D val2D = val.Get<FVector2D>();

    LightVertical(val2D.Y);
    LightHorizontal(val2D.X);
}

void AAVoidCharacter::Die(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if(OtherActor->ActorHasTag(FName("Light"))) return;

    if(OtherActor == this) return;

    OnCharacterDeadDelegate.Broadcast();
}

void AAVoidCharacter::Hit(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    if(OtherActor->ActorHasTag(FName("Light"))) return;

    DEBUG_LOG("Hit.....");
}

// Called every frame
void AAVoidCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(bIsThrowingLight){
        Mechanics->Recover();
    }

}

// Called to bind functionality to input
void AAVoidCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UInputAction *moveCharacterAct = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/Character/IA_MoveCharacter.IA_MoveCharacter"));
    UInputAction *moveLightAct = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/Character/IA_MoveLight.IA_MoveLight"));
    UInputAction *ThrowAct = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/Character/IA_Throw.IA_Throw"));
    UInputAction *StopThrowAct = LoadObject<UInputAction>(nullptr,TEXT("/Game/Input/Character/IA_StopThrow.IA_StopThrow"));

    UInputMappingContext *PlayerMapCtx = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/Input/Character/IMC_PlayerMainCtx.IMC_PlayerMainCtx"));

    if (!moveCharacterAct || !moveLightAct  || !ThrowAct || !StopThrowAct || !PlayerMapCtx  ) {
           UE_LOG(LogTemp, Warning, TEXT(" Load Input Actions or InputMappingContext for player failed...."));
           return;
      }


    if (UEnhancedInputComponent *eic = CastChecked<UEnhancedInputComponent>(InputComponent)){
        eic->BindAction(moveCharacterAct , ETriggerEvent::Triggered , this , &AAVoidCharacter::MoveCharacter );
        eic->BindAction(moveLightAct , ETriggerEvent::Triggered , this , &AAVoidCharacter::MoveLight );

        eic->BindAction(ThrowAct , ETriggerEvent::Triggered , this , &AAVoidCharacter::StartThrow);
        eic->BindAction(ThrowAct , ETriggerEvent::Completed , this , &AAVoidCharacter::ReleaseThrow);
        eic->BindAction(StopThrowAct , ETriggerEvent::Triggered , this , &AAVoidCharacter::StopThrow);
    }

    APlayerController *pc = Cast<APlayerController>(GetController());

    if(UEnhancedInputLocalPlayerSubsystem *subSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer())){
        subSys->AddMappingContext(PlayerMapCtx , 0);
    }
}

