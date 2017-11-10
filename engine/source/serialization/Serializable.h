#ifndef SERIALIZABLE_INCLUDE
#define SERIALIZABLE_INCLUDE

#include "../Globals.h"

class Serializable
{
public:
	virtual const char* GetName() const = 0;
	virtual void PrintDebugInfo() {}
};

#endif