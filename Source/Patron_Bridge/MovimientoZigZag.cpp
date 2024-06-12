// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoZigZag.h"

UMovimientoZigZag::UMovimientoZigZag()
{
    TimePassed = 220.0f;
    Direction = 1.0f;

    //LIMITES DEL ESCENARIO
    LimiteInferior = -1950.0f;      //-X
    LimiteSuperior = 1950.0f;        //X
}

void UMovimientoZigZag::Mover(AActor* Nave)
{
    if (Nave)
    {
        FVector NewLocation = Nave->GetActorLocation();

        // Move the nave forward along the X axis
        NewLocation.X += 5.0f;

        // Update the zigzag movement along the Y axis
        TimePassed += GetWorld()->GetDeltaSeconds();
        if (TimePassed >= 1.0f) // cambiar la direccion cada cieto tiempo
        {
            Direction *= -1.0f;
            TimePassed = 0.0f;
        }

        /* VERIFICAR LOS LIMITES DEL ESCENARIO Y CAMBIAR LA DIRECCION DE MOVIMIENTO SI ES NECESARIO */
        if (NewLocation.X < LimiteInferior || NewLocation.X > LimiteSuperior)
        {
            NewLocation.X *= -1.0f;   // Invertir la dirección en el eje X para rebotar en la pared izquierda o derecha
        }
       

        NewLocation.Y += Direction * 5.0f;

        Nave->SetActorLocation(NewLocation);
    }
}