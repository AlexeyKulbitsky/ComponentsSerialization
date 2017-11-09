#include "GameFactory.h"
#include "EyeComponent.h"

ComponentFactory* gFactory = nullptr;

__declspec(dllexport) ComponentFactory* GetFactory()
{
	gFactory = new ComponentFactory();
	EyeComponent* eyeComponent = new EyeComponent();
	eyeComponent->RegisterProperties();
	gFactory->AddComponent(eyeComponent);

	return gFactory;
}

__declspec(dllexport) GlobalObjectFactory* GetGlobalFactory()
{
	return GlobalObjectFactory::GetInstance();
}

__declspec(dllexport) void PrintDebugInfo()
{
	size_t componentsCount = gFactory->GetComponentCount();
	for (size_t i = 0; i < componentsCount; ++i)
	{
		auto component = gFactory->GetComponent(i);
		component->PrintDebugInfo();
	}
}