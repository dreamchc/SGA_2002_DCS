#include "CGameMode_Combat.h"
#include "Global.h"

ACGameMode_Combat::ACGameMode_Combat()
{
	CContentFinder::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/Blueprints/BP_CPlayer.BP_CPlayer_C'");
}