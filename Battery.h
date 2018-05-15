// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Battery.generated.h"

UCLASS()
class MYPROJECT_API ABattery : public AActor
{
	GENERATED_BODY()


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Battery", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* BatteryMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool bIsActive; // falese when the pickup is deactivated

public:	
	// Sets default values for this actor's properties
	ABattery();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Return mesh for the battery
class UStaticMeshComponent* GetMesh() const { return BatteryMesh; }

	// says if the battery is active or not
	UFUNCTION(BlueprintPure, Category = "Battery")
		bool IsActive();

	// set the battrie's activity sate, false is inactive
	UFUNCTION(BlueprintCallable, Category = "Battery")
		void setActive(bool NewBatteryState);

	//when the pickup gets collected
	UFUNCTION(BlueprintNativeEvent)
	void wasCollected();


	virtual void wasCollected_Implementation();


};


