#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "CMontageManagerComponent.generated.h"

UENUM(BlueprintType)
enum class EMontageAction : uint8
{
	None = 0,
	LightAttack, HeavyAttack, ThrustAttack, SpecialAttack, FallingAttack,
	RollForward, RollLeft, RollRight, RollBackward,
	DrawWeapon, DisarmWeapon,
	StunFront, StunBack, StunRight, StunLeft,
	Impact, Block, Parry, Parried, 
	Backstabbed, Backstab,
	ShootArrow,
};

USTRUCT(BlueprintType)
struct FMontageAction_Asset : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Action;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Montages;
};

USTRUCT(BlueprintType)
struct FMontageAction
{
	GENERATED_USTRUCT_BODY()

public:
	EMontageAction Action;
	class UAnimMontage* Montage;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U2002_05_DCS_API UCMontageManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCMontageManagerComponent();

	virtual void BeginPlay() override;

public:
	class UAnimMontage* GetMontageForAction(EMontageAction Action, uint32 Index);

private:
	void AddDataTable(FString Name, FString Path);
	void PrintDataTable();

	FString GetTableName(EMontageAction Action);

private:
	EMontageAction LastAction;

	TMap<FString, TArray<FMontageAction>> MontageActionMap;
};
