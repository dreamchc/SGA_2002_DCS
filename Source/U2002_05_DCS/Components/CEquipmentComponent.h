#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/CItemHeader.h"
#include "CEquipmentComponent.generated.h"

UENUM(BlueprintType)
enum class ECombatType : uint8
{
	Unarmed, Melee, Range, Magic,
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None, Sword, Axe, Bow, Spell,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInCombatChanged, bool, Combat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatTypeChanged, ECombatType, Type);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWeaponTypeChanged, EWeaponType, Type);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSlotHiddenChanged, EItemType, Type, int32, SlotIndex, FStoredItem, ActiveItem, bool, IsHidden);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U2002_05_DCS_API UCEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCEquipmentComponent();
	void Initialize();

private:
	void UpdateCombatType();

public:
	FORCEINLINE bool GetInCombat() { return InCombat; }
	FORCEINLINE ECombatType GetCombatType() { return CombatType; }

	bool CanMeleeAttack(class UCStateManagerComponent* StateManager);

public:
	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FInCombatChanged OnInCombatChanged;

	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FCombatTypeChanged OnCombatTypeChanged;

	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FWeaponTypeChanged OnWeaponTypeChanged;

	UPROPERTY(BlueprintAssignable, VisibleDefaultsOnly, BlueprintCallable)
		FSlotHiddenChanged OnSlotHiddenChanged;

private:
	bool InCombat;
	ECombatType CombatType;
	EWeaponType WeaponType;
	EItemType SelectedMainHandType = EItemType::MeleeWeapon;
};
