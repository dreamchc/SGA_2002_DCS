#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CMontageManager.generated.h"

UENUM(BlueprintType)
enum class EMontageAction : uint8
{
	None = 0,
	LightAttack, HeavyAttack, SpecialAttack, FallingAttack,
	RollForward, RollLeft, RollRight, RollBackward,
	DrawWeapon, DisarmWeapon,
	StunFront, StunLeft, StunRight, StunBack,
	Impact, Block, Parry, Parried, 
	Backstab, Backstabbed, 
	ShootArrow,
};

USTRUCT(BlueprintType)
struct FMontageAction
{
	GENERATED_USTRUCT_BODY()

public:
	EMontageAction Action;
	TArray<class UAnimMontage *> Montages;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U2002_05_DCS_API UCMontageManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCMontageManager();

public:
	class UAnimMontage* GetMontageForAction(EMontageAction Action, uint32 Index);

private:
	//FMontageAction GetMontage(EMontageAction Action);

private:
	EMontageAction LastAction;
};
