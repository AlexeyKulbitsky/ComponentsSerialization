#include "Serializable.h"
#include "Serializer.h"


void Serializable::Serialize()
{
	Serializer serializer;
	serializer.Serialize(this);
}