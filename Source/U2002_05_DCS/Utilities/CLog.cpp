#include "CLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogProject, Display, All)

CLog::CLog()
{

}

CLog::~CLog()
{

}

void CLog::Print(int val, float time, FColor color, int32 key)
{
	GEngine->AddOnScreenDebugMessage(key, time, color, FString::FromInt(val));
}

void CLog::Print(float val, float time, FColor color, int32 key)
{
	GEngine->AddOnScreenDebugMessage(key, time, color, FString::SanitizeFloat(val));
}

void CLog::Print(const FString & val, float time, FColor color, int32 key)
{
	GEngine->AddOnScreenDebugMessage(key, time, color, val);
}

void CLog::PrintNull(UObject * object, float time, FColor color, int32 key)
{
	GEngine->AddOnScreenDebugMessage(key, time, color, object != NULL ? "Not Null" : "Null");
}

void CLog::Log(int val)
{
	UE_LOG(LogProject, Display, L"%d", val);
}

void CLog::Log(float val)
{
	UE_LOG(LogProject, Display, L"%f", val);
}

void CLog::Log(const FString & val)
{
	UE_LOG(LogProject, Display, L"%s", *val);
}

void CLog::LogNull(UObject * object)
{
	UE_LOG(LogProject, Display, L"%s", object != NULL ? L"Not Null" : L"Null");
}
