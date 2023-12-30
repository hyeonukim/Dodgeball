// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DODGEBALL_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

private: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
	class ULookAtActorComponent* LookAtActorComponent;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bCanSeePlayer = false;

	bool bPreviousCanSeePlayer = false;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 2.f;

	float ThrowingDelay = 0.5f;

	void ThrowDodgeball();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Dodgeball)
	TSubclassOf<class ADodgeballProjectile>DodgeballClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
