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

void UCStateManagerComponent::SetState(EState NewState)
{
	EState prev = CurrentState;

	CurrentState = NewState;

	if (prev != CurrentState)
		OnStateChanged.Broadcast(prev, NewState);
}