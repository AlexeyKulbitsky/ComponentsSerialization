#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

#include "Globals.h"
#include "Component.h"

class MY_TEST_API Entity
{
public:
	Entity();

	int value = 10;

private:
	std::vector<Component*> m_components;
};

extern "C" MY_TEST_API Entity* CreateEntity();

#endif