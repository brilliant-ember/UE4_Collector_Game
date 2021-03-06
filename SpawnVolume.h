// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class MYPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WheretoSpawn; }

	//Find a random point in the spawnvolume BoxComponent
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// the pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ABattery> WhatToSpawn;

	FTimerHandle SpawnTimer;

	// Minimum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayLow;


	//Max spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayHigh;;

private:
	// Box component that specifies where pickups should spawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WheretoSpawn;
	// handles spawning of new Pickups
	void SpawnPickup(); 

	//current spawn delay
	float SpawnDelay;


	
	
};
