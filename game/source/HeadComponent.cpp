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
template<> struct TypeToAnyType<EyeComponent*> { enum { Type = ANY_SERIALIZABLE }; };

void HeadComponent::RegisterObject()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<HeadComponent>();
	
	S_FIELD_PROPERTY("EyeComponent", EyeComponent*, eyeComponent);
}

