#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInputBufferComponent.generated.h"

UENUM(BlueprintType)
enum class EInputBufferKey : uint8
{
	None,
	LightAttack,
	HeavyAttack,
	ThrustAttack,
	SpecialAttack,
	FallingAttack,
	Roll,
	Jump,
	Parry,
	ToggleCombat,
	SwitchMainHandTypeUp,
	SwitchMainHandTypeDown,
	AbilityAttack,
	SetSpellActiveIndex,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputBufferConsumed, EInputBufferKey, Key);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInputBufferOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInputBufferClose);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U2002_05_DCS_API UCInputBufferComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCInputBufferComponent();

public:
	void UpdateKey(EInputBufferKey Key);

private:
	void ConsumeInputBuffer();

public:
	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FInputBufferConsumed OnInputBufferConsumed;
	
	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FInputBufferOpen OnInputBufferOpen;

	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FInputBufferClose OnInputBufferClose;

private:
	EInputBufferKey CurrentKey;
	bool IsOpen;
};
