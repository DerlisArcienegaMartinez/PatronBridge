// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImplementacionMovimiento.h"
#include "NaveEnemiga.generated.h"

UCLASS(Abstract)
class PATRON_BRIDGE_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* mallaNaveEnemiga;
	
public:	
	ANaveEnemiga();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	TScriptInterface<IImplementacionMovimiento> Movimiento;   	// Implementamos el patron Bridge dentro de NaveEnemiga

	
	 void MovimientoBridge(float DeltaTime);  // Funcion para realizar el movimiento
};
