#include "CStateManagerComponent.h"

UCStateManagerComponent::UCStateManagerComponent()
{
	
}

bool UCStateManagerComponent::IsStateEqualPure(EState State)
{
	return GetState() == State;
}

bool UCStateManagerComponent::IsAlive()
{
	return !IsStateEqualPure(EState::Dead);
}
