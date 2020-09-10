#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CStateManagerComponent.h"
#include "Components/CEquipmentComponent.h"
#include "Components/CInputBufferComponent.h"
#include "Components/CMontageManagerComponent.h"
#include "CPlayer.generated.h"

UCLASS()
class U2002_05_DCS_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Camera")
		float HorizontalLookRate = 45;

	UPROPERTY(EditAnywhere, Category = "Camera")
		float VerticalLookRate = 45;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* FollowCamera;

	
	UPROPERTY(VisibleDefaultsOnly)
		class UCStateManagerComponent* StateManager;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCEquipmentComponent* Equipment;

	UPROPERTY(VisibleDefaultsOnly)
		class UCInputBufferComponent* InputBuffer;

	UPROPERTY(VisibleDefaultsOnly)
		class UCMontageManagerComponent* MontageManager;

public: //Component Return
	FORCEINLINE class UCEquipmentComponent* GetEquipment() { return Equipment; }


public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//class UAnimMontage* GetMontages

private: //Bind Axis
	void HorizontalLook(float Axis);
	void VerticalLook(float Axis);
	void MoveForward(float Axis);
	void MoveRight(float Axis);

private: //Bind Action
	void Attack();

private: //Delegated
	UFUNCTION()
		void OnInputBufferConsumed(EInputBufferKey Key);

	UFUNCTION()
		void OnStateChagned(EState PrevState, EState NewState);

private: //InputBufferEvent
	void ToggleCombat();

private:
	bool AttemptBackstab();
};
