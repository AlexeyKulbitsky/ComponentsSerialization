#include "EyeComponent.h"

#include "serialization/GlobalObjectFactory.h"
#include <iostream>

EyeComponent::EyeComponent()
{
	std::cout << "EyeComponent has been created" << std::endl;
}

const char* EyeComponent::GetName() const
{
	return typeid(EyeComponent).name();
}

void EyeComponent::RegisterProperties()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<EyeComponent>();
	m_properties.push_back(new Property(&this->size, "size"));
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