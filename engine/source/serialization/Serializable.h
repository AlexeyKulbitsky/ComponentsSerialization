#ifndef SERIALIZABLE_INCLUDE
#define SERIALIZABLE_INCLUDE

#include "../Globals.h"

#include "Property.h"

class Serializable
{
public:
	virtual const char* GetName() const = 0;
	virtual void RegisterProperties() {}
	virtual void PrintDebugInfo() {}

	std::vector<Property*> GetProperties();

protected:
	std::vector<Property*> m_properties;
};

#endif