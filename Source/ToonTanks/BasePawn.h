// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 EditAnywhereInt = 13;

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 14;

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt = 15;

	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt = 16;

	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 17;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 400.f;

private:
	UPROPERTY()
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY()
	UStaticMeshComponent* BaseMesh;

	UPROPERTY()
	UStaticMeshComponent* TurretMesh;

	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
