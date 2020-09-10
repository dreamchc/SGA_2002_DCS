#pragma once

#include "CoreMinimal.h"
#include "Items/Displayed/CDisplayedItem.h"
#include "CDisplayedItem_Hand.generated.h"

UCLASS()
class U2002_05_DCS_API ACDisplayedItem_Hand : public ACDisplayedItem
{
	GENERATED_BODY()
	
public:
	ACDisplayedItem_Hand();

protected:
	virtual void BeginPlay() override;


private:
	void OnSlotHiddenChanged(EItemType Type, int32 SlotIndex, FStoredItem ActiveItem, bool IsHidden);
};
