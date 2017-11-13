#ifndef SERIALIZER_INCLUDE
#define SERIALIZER_INCLUDE

class Serializable;

class Serializer
{
public:
	void Serialize(Serializable* serializable);
};

#endif
