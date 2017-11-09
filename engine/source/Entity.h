#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

#include "Globals.h"
#include "Component.h"

class Entity
{
public:
	Entity();

	int value = 10;

private:
	std::vector<Component*> m_components;
};

#endif