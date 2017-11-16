#include "EyeComponent.h"

#include "serialization/GlobalObjectFactory.h"
#include "serialization/Property.h"
#include <iostream>

EyeComponent::EyeComponent()
{
	std::cout << "EyeComponent has been created" << std::endl;
}

void EyeComponent::RegisterObject()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<EyeComponent>();
	S_FIELD_PROPERTY("Size", size);
	S_FIELD_PROPERTY("Depth", depth);
	S_FIELD_PROPERTY("Name", name);
	S_ACCESSOR_PROPERTY("Age", GetAge, SetAge);
}

void EyeComponent::PrintDebugInfo()
{
	
}
