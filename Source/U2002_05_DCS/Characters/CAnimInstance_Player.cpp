#include "CAnimInstance_Player.h"
#include "Global.h"

void UCAnimInstance_Player::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Player = Cast<ACPlayer>(TryGetPawnOwner());
}

void UCAnimInstance_Player::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	CheckNull(Player);


	InAir = Player->GetCharacterMovement()->IsFalling();
	Speed = Player->GetVelocity().Size2D();
	Direction = CalculateDirection(Player->GetVelocity(), Player->GetActorRotation());
}
