#ifndef GAME_FACTORY_INCLUDE
#define GAME_FACTORY_INCLUDE

#include <ComponentFactory.h>
#include <serialization/GlobalObjectFactory.h>

extern "C" __declspec(dllexport) ComponentFactory* GetFactory();
extern "C" __declspec(dllexport) GlobalObjectFactory* GetGlobalFactory();
extern "C" __declspec(dllexport) void PrintDebugInfo();

#endif
