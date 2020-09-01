#include "UnitTest_DataSheet.h"
#include "Global.h"

UUnitTest_DataSheet::UUnitTest_DataSheet()
{
	CContentFinder::GetAsset<UDataTable>(&DataTable, "DataTable'/Game/UnitTest/Weapon.Weapon'");

	DataTable->GetAllRows("", DataArray);
}

const FTestDataSheet* UUnitTest_DataSheet::GetRow(int RowIndex)
{
	return DataArray[RowIndex];
}


const FTestDataSheet* UUnitTest_DataSheet::GetRow(FString RowName)
{
	for (FTestDataSheet* sheet : DataArray)
	{
		if (sheet->Name.ToString() == RowName)
			return sheet;
	}

	return NULL;
}