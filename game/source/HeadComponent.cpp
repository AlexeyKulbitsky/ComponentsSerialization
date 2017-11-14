#include "HeadComponent.h"
#include "serialization/GlobalObjectFactory.h"
#include "serialization/Property.h"
#include <iostream>

HeadComponent::HeadComponent()
{
	std::cout << "HeadComponent has been created" << std::endl;
}

const char* HeadComponent::GetName() const
{
	return typeid(HeadComponent).name();
}

template<typename T, bool = std::is_pointer<T>::value>
struct RemovePointer
{
	using Type = T;
};

template<typename T>
struct RemovePointer < T, true >
{
//	using Type = std::remove_pointer<T>::type;
};

void HeadComponent::RegisterObject()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<HeadComponent>();
	
	//S_FIELD_PROPERTY_EXT("EyeComponent", EyeComponent*, Serializable*, eyeComponent);

	//S_ACCESSOR_PROPERTY_EXT("EyeComponent", EyeComponent*, Serializable*, GetEyeComponent, SetEyeComponent);
	//S_ACCESSOR_PROPERTY_TEST("EyeComponent", EyeComponent*, GetEyeComponent, SetEyeComponent);
	//CreateProperty(&HeadComponent::Get, &HeadComponent::Set, "EyeComponent");

	S_ACCESSOR_PROPERTY("EyeComponent", Get, Set);
	S_ACCESSOR_PROPERTY("BrainWeight", GetBrainWeight, SetBrainWeight);

	int a = 0;
	a++;
}

