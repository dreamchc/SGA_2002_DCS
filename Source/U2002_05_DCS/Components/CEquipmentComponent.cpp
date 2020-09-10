#include "CEquipmentComponent.h"
#include "Global.h"
#include "CStateManagerComponent.h"

UCEquipmentComponent::UCEquipmentComponent()
{

}

void UCEquipmentComponent::Initialize()
{
	UpdateCombatType();
}

void UCEquipmentComponent::UpdateCombatType()
{
	ECombatType prevCombatType = CombatType;
	EWeaponType weaponType = WeaponType;


}

bool UCEquipmentComponent::CanMeleeAttack(UCStateManagerComponent* StateManager)
{
	bool combatType = false;
	combatType |= CombatType == ECombatType::Unarmed;
	combatType |= CombatType == ECombatType::Melee;

	bool b = true;
	b &= combatType;
	b &= StateManager->IsStateEqualPure(EState::Idle);
	b &= GetInCombat();

	return b;
}