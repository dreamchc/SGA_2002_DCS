#include "CDisplayedItem.h"
#include "Global.h"
#include "Components/PrimitiveComponent.h"
#include "Components/CEquipmentComponent.h"

ACDisplayedItem::ACDisplayedItem()
{
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	RootComponent = Scene;

	
}

void ACDisplayedItem::BeginPlay()
{
	Super::BeginPlay();
	
	Equipment = Cast<UCEquipmentComponent>(GetOwner()->GetComponentByClass(UCEquipmentComponent::StaticClass()));
	
	UPrimitiveComponent* component = GetPrimaryComponent();
	CheckNull(component);

	component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACDisplayedItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

UPrimitiveComponent* ACDisplayedItem::GetPrimaryComponent()
{
	UPrimitiveComponent* component = NULL;

	component = Cast<UPrimitiveComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	if (component != NULL) return component;

	component = Cast<UPrimitiveComponent>(GetComponentByClass(USkeletalMeshComponent::StaticClass()));
	if (component != NULL) return component;

	return Cast<UPrimitiveComponent>(GetComponentByClass(UParticleSystemComponent::StaticClass()));
}

bool ACDisplayedItem::AttachItem()
{
	UPrimitiveComponent* meshComponent = GetPrimaryComponent();
	CheckNullResult(meshComponent, false);

	FName name = GetAttachmentSocket();
	USceneComponent* parent = Cast<ACharacter>(GetOwner())->GetMesh();
	meshComponent->AttachToComponent(parent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), name);

	return true;
}

void ACDisplayedItem::SetSimulatePhysics()
{
	UPrimitiveComponent* meshComponent = GetPrimaryComponent();

	meshComponent->SetCollisionProfileName("Ragdoll");
	meshComponent->SetSimulatePhysics(true);
}