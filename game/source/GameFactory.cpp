#include "GameFactory.h"
#include "EyeComponent.h"

ObjectsRegistrator registrator;

ObjectsRegistrator::ObjectsRegistrator()
{
	EyeComponent::RegisterObject();
}

__declspec(dllexport) GlobalObjectFactory* GetGlobalFactory()
{
	return GlobalObjectFactory::GetInstance();
}

