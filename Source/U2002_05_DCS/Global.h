#pragma once

#include "Utilities/CLog.h"
#include "Utilities/CContentFinder.h"

#include "Characters/CPlayer.h"

#include "ConstructorHelpers.h"
#include "DrawDebugHelpers.h"

#include "Engine/World.h"
#include "TimerManager.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"


#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

#include "Camera/CameraComponent.h"

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"


#define CheckNull(p){ if(p == NULL) return; }
#define CheckNullResult(p, result){ if(p == NULL) return result; }

#define CheckTrue(p){ if(p == true) return; }
#define CheckTrueResult(p, result){ if(p == true) return result; }

#define CheckFalse(p){ if(p == false) return; }
#define CheckFalseResult(p, result){ if(p == false) return result; }