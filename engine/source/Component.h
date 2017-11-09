#ifndef COMPONENT_INCLUDE
#define COMPONENT_INCLUDE

#include "Globals.h"
#include "serialization/Serializable.h"

class Component : public Serializable
{
public:
	Component();
	virtual const char* GetName() const override;
};

#endif
