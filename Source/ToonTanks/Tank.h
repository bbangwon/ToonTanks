// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputMappingContext* DefaultContext;

	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputAction* MoveForwardAction;

	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputAction* TurnAction;

	UPROPERTY(VisibleAnywhere, Category = Input)
	class UInputAction* RotateTurretAction;

	void Move_Enhanced(const struct FInputActionValue& Value);

	void Move(float Value);
};