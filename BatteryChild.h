// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Battery.h"
#include "BatteryChild.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ABatteryChild : public ABattery
{
	GENERATED_BODY()
public:
		// Sets default values for this actor's properties
		ABatteryChild();
		
		//Override was collected function, use implementaion bcs it's a 
		//Blueprint native event
		void wasCollected_Implementation() override;

		//getter for the BatteryPower
		float GetPower();

protected:
	// the amount of power the battery gives
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float BatteryPower;
};
