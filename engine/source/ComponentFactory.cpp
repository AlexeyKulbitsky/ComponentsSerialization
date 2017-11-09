#include "ComponentFactory.h"

#include "Component.h"

void ComponentFactory::AddComponent(Component* component)
{
	m_components.push_back(component);
}

size_t ComponentFactory::GetComponentCount() const
{
	return m_components.size();
}

Component* ComponentFactory::GetComponent(size_t index)
{
	if (index >= m_components.size())
		return nullptr;
	return m_components[index];
}

Component* ComponentFactory::GetComponent(const std::string& name)
{
	for (auto component : m_components)
	{
		if (name == component->GetName())
			return component;
	}
	return nullptr;
}
