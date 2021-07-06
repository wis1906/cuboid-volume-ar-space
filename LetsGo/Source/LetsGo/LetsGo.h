#pragma once

#include "EngineMinimal.h"
#include <iostream>

#define PRINTF(txt,...) UE_LOG(LetsGo, Warning, TEXT(txt), __VA_ARGS__)

DECLARE_LOG_CATEGORY_EXTERN(LetsGo, Log, All);

inline void printShort(const char* s)
{
	FString str(s);
	UE_LOG(LetsGo, Warning, TEXT("%s"), *str);
}

inline void printShort(std::string s)
{
	const char* sc = s.c_str();
	FString str(sc);
	UE_LOG(LetsGo, Warning, TEXT("%s"), *str);
}

inline void printShort(FString s)
{
	UE_LOG(LetsGo, Warning, TEXT("%s"), *s);
}