#include "Entity.h"

#include <iostream>

Entity::Entity()
{
	std::cout << "Entity Constructor!" << std::endl;
}

 
MY_TEST_API Entity* CreateEntity()
{
	return new Entity();
}