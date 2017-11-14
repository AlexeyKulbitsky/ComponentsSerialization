#include "EyeComponent.h"

#include "serialization/GlobalObjectFactory.h"
#include "serialization/Property.h"
#include <iostream>

EyeComponent::EyeComponent()
{
	std::cout << "EyeComponent has been created" << std::endl;
}

const char* EyeComponent::GetName() const
{
	return typeid(EyeComponent).name();
}

void EyeComponent::RegisterObject()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<EyeComponent>();
	S_FIELD_PROPERTY("Size", int, size);
	S_FIELD_PROPERTY("Depth", float, depth);
	S_FIELD_PROPERTY("Name", std::string, name);
	S_ACCESSOR_PROPERTY("Age", GetAge, SetAge);
}

void EyeComponent::PrintDebugInfo()
{
	std::cout << (*this);
}

std::ostream& operator<<(std::ostream& s, const EyeComponent& c)
{
	s << "---Component:: " << c.GetName() << std::endl
		<< "Size: " << c.size << std::endl
		<< "Depth: " << c.depth << std::endl
		<< "Name: " << c.name << std::endl;
	return s;
}