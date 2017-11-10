#ifndef GAME_FACTORY_INCLUDE
#define GAME_FACTORY_INCLUDE

#include <serialization/GlobalObjectFactory.h>

struct ObjectsRegistrator
{
public:
	ObjectsRegistrator();
};

extern "C" __declspec(dllexport) GlobalObjectFactory* GetGlobalFactory();

#endif
