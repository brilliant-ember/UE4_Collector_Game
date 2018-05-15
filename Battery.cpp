// Fill out your copyright notice in the Description page of Project Settings.

#include "Battery.h"
#include "MyProject.h"


// Sets default values
ABattery::ABattery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bIsActive = true;

	BatteryMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PICKUPMESH"));

	//RootComponent = BatteryMesh;

}

// Called when the game starts or when spawned
void ABattery::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//getter
bool ABattery::IsActive() {
	return bIsActive;
}

//setter
void ABattery::setActive(bool NewBatteryState)
{
	bIsActive = NewBatteryState;
}

void ABattery::wasCollected_Implementation() {
	//print a debug message
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("you collected %s"), *PickupDebugString);
}




