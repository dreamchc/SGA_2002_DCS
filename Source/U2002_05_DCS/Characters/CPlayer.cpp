#include "CPlayer.h"
#include "Global.h"
#include "GameFramework/SpringArmComponent.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 540, 0);


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetCapsuleComponent());

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom);


	CameraBoom->TargetArmLength = 450;
	CameraBoom->SocketOffset = FVector(0, 0, 180);
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->bEnableCameraRotationLag = true;

	FollowCamera->RelativeRotation = FRotator(-15, 0, 0);


	StateManager = CreateDefaultSubobject<UCStateManagerComponent>("StateManager");
	Equipment = CreateDefaultSubobject<UCEquipmentComponent>("Equipment");
	
	InputBuffer = CreateDefaultSubobject<UCInputBufferComponent>("InputBuffer");

	MontageManager = CreateDefaultSubobject<UCMontageManagerComponent>("MontageManager");
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	InputBuffer->OnInputBufferConsumed.AddDynamic(this, &ACPlayer::OnInputBufferConsumed);
	StateManager->OnStateChanged.AddDynamic(this, &ACPlayer::OnStateChagned);


	Equipment->Initialize();
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::HorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::VerticalLook);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::MoveRight);


	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &ACPlayer::Attack);
}

void ACPlayer::HorizontalLook(float Axis)
{
	AddControllerYawInput(Axis * HorizontalLookRate * GetWorld()->GetDeltaSeconds());
}

void ACPlayer::VerticalLook(float Axis)
{
	AddControllerPitchInput(Axis * VerticalLookRate * GetWorld()->GetDeltaSeconds());
}

void ACPlayer::MoveForward(float Axis)
{
	CheckFalse(StateManager->IsAlive());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector();

	AddMovementInput(direction, Axis);
}

void ACPlayer::MoveRight(float Axis)
{
	CheckFalse(StateManager->IsAlive());

	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector();

	AddMovementInput(direction, Axis);
}

void ACPlayer::Attack()
{
	if (Equipment->GetInCombat() == false)
	{
		InputBuffer->UpdateKey(EInputBufferKey::ToggleCombat);

		return;
	}

	if (Equipment->GetCombatType() == ECombatType::Melee)
	{

	}
	else
	{
		CheckFalse(Equipment->GetCombatType() == ECombatType::Unarmed);

		InputBuffer->UpdateKey(EInputBufferKey::LightAttack);
	}
}

void ACPlayer::OnInputBufferConsumed(EInputBufferKey Key)
{
	CheckFalse(StateManager->IsAlive());

	switch (Key)
	{
		case EInputBufferKey::ToggleCombat: ToggleCombat(); break;
	}
}

void ACPlayer::OnStateChagned(EState PrevState, EState NewState)
{
	//TODO
	//Update Blocking
	//Update Zoom
	//Update Rotation Setting
	//Abillity on State Changed

	//Reset Melee Attack type when Attack state ends
	//Archery - Drawing Sound
}

void ACPlayer::ToggleCombat()
{
	CheckFalse(StateManager->IsStateEqualPure(EState::Idle));

	StateManager->SetState(EState::Interacting);

	EMontageAction action = Equipment->GetInCombat() ? EMontageAction::DisarmWeapon : EMontageAction::DrawWeapon;
	UAnimMontage* montage = MontageManager->GetMontageForAction(action, 0);

	checkf(montage != NULL, L"montage != NULL");
	
	PlayAnimMontage(montage);
}

bool ACPlayer::AttemptBackstab()
{
	CheckFalseResult(Equipment->CanMeleeAttack(StateManager), false);

	FVector start = GetActorLocation();
	FVector end = start + GetActorForwardVector() * 150;

	FHitResult result;
	TArray<AActor *> ignoreActors;
	UKismetSystemLibrary::LineTraceSingle
	(
		GetWorld(), start, end, ETraceTypeQuery::TraceTypeQuery1, false, ignoreActors,
		EDrawDebugTrace::None, result, true
	);

	return false;
}