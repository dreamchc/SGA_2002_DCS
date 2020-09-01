#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "UnitTest_DataSheet.generated.h"

USTRUCT(BlueprintType)
struct FTestDataSheet : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Power;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float PlayRate;
};

UCLASS()
class U2002_05_DCS_API UUnitTest_DataSheet : public UObject
{
	GENERATED_BODY()
	
public:
	UUnitTest_DataSheet();

public:
	const FTestDataSheet* GetRow(int RowIndex);
	const FTestDataSheet* GetRow(FString RowName);

	int GetRowCount() { return DataArray.Num(); }
	const TArray<FTestDataSheet *>& GetDataArray() { return DataArray; }

private:
	UDataTable* DataTable;

	TArray<FTestDataSheet *> DataArray;
};
