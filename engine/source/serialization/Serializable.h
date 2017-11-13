#ifndef SERIALIZABLE_INCLUDE
#define SERIALIZABLE_INCLUDE

#include "../Globals.h"

#define SHADOW_OBJECT(TypeName)										\
public:																\
using ClassType = TypeName;											\
static const char* GetTypeNameStatic() { return #TypeName; }		\
virtual const char* GetTypeName() { return GetTypeNameStatic(); }

class Serializable
{
	SHADOW_OBJECT(Serializable)
public:
	virtual const char* GetName() const = 0;
	virtual void PrintDebugInfo() {}
	virtual void Serialize();
};

#endif