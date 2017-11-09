#ifndef COMPONENT_FACTORY_INCUDE
#define COMPONENT_FACTORY_INCUDE

#include "Globals.h"

class Component;

class ComponentFactory
{
public:
	void AddComponent(Component* component);
	size_t GetComponentCount() const;
	Component* GetComponent(size_t index);
	Component* GetComponent(const std::string& name);

private:
	std::vector<Component*> m_components;
};

#endif