#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateManagerComponent.generated.h"

UENUM(BlueprintType)
enum class EState : uint8
{
	Idle, Disable, Atacking, Rolling, Falling, Backstabbing, Parrying, Interacting, Dead,
};

UENUM(BlueprintType)
enum class EActivity : uint8
{
	None, IsBlockingPressed, IsAimingPressed, IsImmortal, CantBeInterrupted, IsLookingForward, CanParryHit, IsZooming,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateChanged, EState, PrevState, EState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActivityChanged, EActivity, Activity, bool, Value);

UCLASS( ClassGroup=(Combat), meta=(BlueprintSpawnableComponent) )
class U2002_05_DCS_API UCStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStateManagerComponent();

public:
	FORCEINLINE EState GetState() { return CurrentState; }

public:
	bool IsStateEqualPure(EState State);
	bool IsAlive();

	void SetState(EState NewState);

public:
	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FStateChanged OnStateChanged;

	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FActivityChanged OnActivityChanged;

private:
	EState CurrentState;
	FTimerHandle IdleStateTimer;
};
