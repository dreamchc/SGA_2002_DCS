#include "CInputBufferComponent.h"
#include "Global.h"

UCInputBufferComponent::UCInputBufferComponent()
{

}

void UCInputBufferComponent::UpdateKey(EInputBufferKey Key)
{
	CurrentKey = Key;

	if (IsOpen == false)
		ConsumeInputBuffer();
}

void UCInputBufferComponent::ConsumeInputBuffer()
{
	if (OnInputBufferConsumed.IsBound())
		OnInputBufferConsumed.Broadcast(CurrentKey);

	CurrentKey = EInputBufferKey::None;
}