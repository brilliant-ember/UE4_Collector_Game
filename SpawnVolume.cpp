// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnVolume.h"
#include "Classes/Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"	
#include "Battery.h"
#include "Public/TimerManager.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//create the UBox spawn volume where to span
	WheretoSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WheretoSpawn;

	//Set the Spawn Delay Range
	SpawnDelayLow = 1.0f;
	SpawnDelayHigh = 4.5f;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	SpawnDelay = FMath::FRandRange(SpawnDelayLow, SpawnDelayHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandomPoint(){
	FVector SpawnOrigin = WheretoSpawn->Bounds.Origin;
	FVector SpawnExtent = WheretoSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SpawnPickup() {
	/* 1) If you have something to spawn
		2) Check for a valid World
		3) Set Spawn Parameters
		4) Spawn the Pickup
		*/
	//1
	if (WhatToSpawn != NULL) {
		//2
		UWorld* const World = GetWorld();
		if (World) {
			//3
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// Get a arandom spawn postion
			FVector SpawnLocation = GetRandomPoint();
			//random rotation so battries are spawned randomly
			FRotator SpawnRotaion;
			SpawnRotaion.Yaw = FMath::FRand() *360.0f;
			SpawnRotaion.Pitch = FMath::FRand() *360.0f;
			SpawnRotaion.Roll = FMath::FRand() *360.0f;

			//4 Spawn the pickup
			ABattery* const SpawnedBattery = World->SpawnActor<ABattery>(WhatToSpawn, SpawnLocation, SpawnRotaion, SpawnParams);

			SpawnDelay = FMath::FRandRange(SpawnDelayLow, SpawnDelayHigh);
			
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		}

	}
}

