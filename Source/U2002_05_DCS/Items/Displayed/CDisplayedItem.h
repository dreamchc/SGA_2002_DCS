#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/CItemHeader.h"
#include "CDisplayedItem.generated.h"

UCLASS()
class U2002_05_DCS_API ACDisplayedItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ACDisplayedItem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE FName GetAttachmentSocket() { return AttachmentSocket; }

protected:
	bool AttachItem();

private:
	class UPrimitiveComponent* GetPrimaryComponent();
	void SetSimulatePhysics();

protected:
	class USceneComponent* Scene;

	class UCEquipmentComponent* Equipment;
	EItemType Type;
	int32 SlotIndex;

	FName AttachmentSocket;
};
