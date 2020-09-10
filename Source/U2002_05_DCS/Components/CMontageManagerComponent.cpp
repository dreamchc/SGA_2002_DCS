#include "CMontageManagerComponent.h"
#include "Global.h"
#include "CEquipmentComponent.h"

UCMontageManagerComponent::UCMontageManagerComponent()
{
	AddDataTable("AI_1H", "/Game/DataTables/AI_1H");
	AddDataTable("AI_Archer", "/Game/DataTables/AI_Archer");
	AddDataTable("AI_Mage", "/Game/DataTables/AI_Mage");
	AddDataTable("Player_1H", "/Game/DataTables/Player_1H");
	AddDataTable("Player_AR", "/Game/DataTables/Player_AR");
	AddDataTable("Player_Common", "/Game/DataTables/Player_Common");
	AddDataTable("Player_Magic", "/Game/DataTables/Player_Magic");
	AddDataTable("Player_U", "/Game/DataTables/Player_U");
}

void UCMontageManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	//PrintDataTable();
}

UAnimMontage* UCMontageManagerComponent::GetMontageForAction(EMontageAction Action, uint32 Index)
{
	LastAction = Action;

	FString keyName = GetTableName(LastAction);
	CLog::Log(keyName);

	if (MontageActionMap.Contains(keyName) == false)
		return NULL;
	
	return MontageActionMap[keyName][Index].Montage;
}

FString UCMontageManagerComponent::GetTableName(EMontageAction Action)
{
	EMontageAction action = Action;

	TArray<EMontageAction> commonActions =
	{
		EMontageAction::Backstabbed,
		EMontageAction::RollForward, EMontageAction::RollLeft, EMontageAction::RollRight, EMontageAction::RollBackward
	};

	CheckTrueResult(commonActions.Contains(LastAction), "Player_Common");
	
	UCEquipmentComponent* equipment = Cast<ACPlayer>(GetOwner())->GetEquipment();
	if (equipment->GetInCombat() == false)
	{
		TArray<EMontageAction> tempActions =
		{
			EMontageAction::DisarmWeapon, EMontageAction::DrawWeapon
		};
		
		if (tempActions.Contains(action) == false)
			return "Player_U";
	}

	switch(equipment->GetCombatType())
	{
		case ECombatType::Unarmed: return "Player_U";
		case ECombatType::Melee: return "Player_1H";
		case ECombatType::Range: return "Player_AR";
		case ECombatType::Magic: return "Player_Magic";
	}

	return "";
}

void UCMontageManagerComponent::AddDataTable(FString Name, FString Path)
{
	UDataTable* dataTable;
	CContentFinder::GetAsset(&dataTable, Path);

	TArray<FMontageAction_Asset *> arr;
	dataTable->GetAllRows("", arr);

	TArray<FMontageAction> actionArr;
	for (FMontageAction_Asset* temp : arr)
	{
		FMontageAction action;
		action.Action = (EMontageAction)temp->Action;

		FString path = temp->Montages;
		CContentFinder::GetAsset<UAnimMontage>(&action.Montage, path);

		actionArr.Add(action);
	}

	MontageActionMap.Add(Name, actionArr);
}

void UCMontageManagerComponent::PrintDataTable()
{
	for (TPair<FString, TArray<FMontageAction>> pair : MontageActionMap)
	{
		CLog::Log("DataTable : " + pair.Key);

		for (const FMontageAction& action : pair.Value)
		{
			FString str1 = FString::FromInt((int)action.Action);
			FString str2 = ", ";
			FString str3 = action.Montage->GetPathName();

			CLog::Log(str1 + str2 + str3);
		}
	}
}