// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Components/AudioComponent.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float GetTotalMassOnPlate() const;
	void SetupAudioComponent();

		
private:

	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.0f;

	//tracks if sound has been played
	bool OpenDoorSoundPlayed = false;
	bool CloseDoorSoundPlayed = true;

	UPROPERTY(EditAnywhere)
		float MassRequiredForPlate = 50.f;

	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;

	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
		float DoorCloseSpeed = 2.5f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;
};
