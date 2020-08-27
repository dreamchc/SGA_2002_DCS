#pragma once

#include "CoreMinimal.h"
#include "ConstructorHelpers.h"

class U2002_05_DCS_API CContentFinder
{
public:
	template<typename T>
	static void GetClass(TSubclassOf<T>* OutObject, FString Path)
	{
		ConstructorHelpers::FClassFinder<T> asset(*Path);
		verify(asset.Succeeded());

		*OutObject = asset.Class;
	}

public:
	template<typename T>
	static void GetAsset(T** OutObject, FString Path)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*Path);
		verify(asset.Succeeded());

		*OutObject = asset.Object;
	}
};