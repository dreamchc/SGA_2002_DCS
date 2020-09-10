#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Items/Object/CObjectItem.h"
#include "CItemHeader.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	None, Spell, Sheild, Head, Top, Legs, Hands, Feet,
	Arrows, Tool, Material, Ring,
	MeleeWeapon, RangeWeapon, Necklace
};

USTRUCT(BlueprintType)
struct FStoredItem
{
	GENERATED_USTRUCT_BODY()

public:
	FGuid Id;
	TSubclassOf<class UCObjectItem> ItemClass;
	int32 Amount;
};

UCLASS()
class U2002_05_DCS_API UCItemHeader : public UObject
{
	GENERATED_BODY()
	
public:
	UCItemHeader();
};
