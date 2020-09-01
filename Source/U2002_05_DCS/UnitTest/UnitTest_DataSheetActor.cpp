#include "UnitTest_DataSheetActor.h"
#include "Global.h"
#include "UnitTest/UnitTest_DataSheet.h"

AUnitTest_DataSheetActor::AUnitTest_DataSheetActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AUnitTest_DataSheetActor::BeginPlay()
{
	Super::BeginPlay();

	Sheet = NewObject<UUnitTest_DataSheet>();
	
	for (int i = 0; i < Sheet->GetRowCount(); i++)
		CLog::Log(Sheet->GetRow(i)->Name.ToString());
}

// Called every frame
void AUnitTest_DataSheetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

