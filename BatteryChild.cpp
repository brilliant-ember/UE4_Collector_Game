// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryChild.h"
#include "MyProject.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


ABatteryChild::ABatteryChild(){

	GetMesh()->SetSimulatePhysics(true);

	//base power for the battery
	BatteryPower = +150.f;

}

void ABatteryChild::wasCollected_Implementation(){
	//use base behaviour
	Super::wasCollected_Implementation();
	UE_LOG(LogClass, Log, TEXT("THE WAS COLLECTED IMPEM %s"));
	Destroy();
}
float ABatteryChild::GetPower() { return BatteryPower; }




