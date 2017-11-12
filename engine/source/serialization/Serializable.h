#ifndef SERIALIZABLE_INCLUDE
#define SERIALIZABLE_INCLUDE

#include "../Globals.h"

#define SHADOW_OBJECT(TypeName)								\
public:														\
using ClassType = TypeName;									\
static const char* GetTypeName() { return #TypeName; }

class Serializable
{
	SHADOW_OBJECT(Serializable)
public:
	virtual const char* GetName() const = 0;
	virtual void PrintDebugInfo() {}
};

#endif