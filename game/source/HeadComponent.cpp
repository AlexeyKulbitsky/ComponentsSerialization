#include "HeadComponent.h"
#include "serialization/GlobalObjectFactory.h"
#include "serialization/Property.h"
#include <iostream>

HeadComponent::HeadComponent()
{
	std::cout << "HeadComponent has been created" << std::endl;
}

const char* HeadComponent::GetName() const
{
	return typeid(HeadComponent).name();
}

void HeadComponent::RegisterObject()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<HeadComponent>();
	
	//S_FIELD_PROPERTY_EXT("EyeComponent", EyeComponent*, Serializable*, eyeComponent);

	S_ACCESSOR_PROPERTY_EXT("EyeComponent", EyeComponent*, Serializable*, GetEyeComponent, SetEyeComponent);
	//S_ACCESSOR_PROPERTY_TEST("EyeComponent", EyeComponent*, GetEyeComponent, SetEyeComponent);
	EyeComponent* a = nullptr;
	CreateProperty(&HeadComponent::Get, &HeadComponent::Set, "EyeComponent");
}

