#include "CDisplayedItem_Hand.h"
#include "Global.h"

ACDisplayedItem_Hand::ACDisplayedItem_Hand()
{

}

void ACDisplayedItem_Hand::BeginPlay()
{
	Super::BeginPlay();

	Equipment->OnSlotHiddenChanged.AddDynamic(this, &ACDisplayedItem_Hand::OnSlotHiddenChanged);
}

void ACDisplayedItem_Hand::OnSlotHiddenChanged(EItemType Type, int32 SlotIndex, FStoredItem ActiveItem, bool IsHidden)
{
	CheckFalse(Equipment->GetInCombat());
	
	bool b = true;
	b &= this->Type == Type;
	b &= this->SlotIndex == SlotIndex;
	CheckFalse(b);

	AttachItem();
}
