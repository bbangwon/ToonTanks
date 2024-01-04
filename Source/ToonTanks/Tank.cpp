// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"


ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//Enhanced Input
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> DEFAULT_CONTEXT(TEXT("/Game/Input/Actions/iMC_Tank"));
	if (DEFAULT_CONTEXT.Succeeded())
		DefaultContext = DEFAULT_CONTEXT.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_MOVE_FORWARD(TEXT("/Game/Input/Actions/iA_MoveForward"));
	if (IA_MOVE_FORWARD.Succeeded())
		MoveForwardAction = IA_MOVE_FORWARD.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_TURN(TEXT("/Game/Input/Actions/iA_Turn"));
	if (IA_TURN.Succeeded())
		TurnAction = IA_TURN.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_ROTATE_TURRET(TEXT("/Game/Input/Actions/iA_RotateTurret"));
	if (IA_ROTATE_TURRET.Succeeded())
		RotateTurretAction = IA_ROTATE_TURRET.Object;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	//Enhanced Input
	//if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	//{
	//	if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	//	{
	//		SubSystem->AddMappingContext(DefaultContext, 0);
	//	}
	//}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Enhanced Input
	//if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	//{
	//	EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ATank::Move_Enhanced);
	//}

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move_Enhanced(const FInputActionValue& Value)
{
	float v = Value.Get<float>();
	UE_LOG(LogTemp, Display, TEXT("Move : %f"), v);
}

void ATank::Move(float Value)
{
	FVector DeltaLocation = FVector::ZeroVector;

	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation);
}



