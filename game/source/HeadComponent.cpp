#include "HeadComponent.h"
#include "serialization/GlobalObjectFactory.h"
#include "serialization/Property.h"
#include <iostream>

HeadComponent::HeadComponent()
{
	std::cout << "HeadComponent has been created" << std::endl;
}

void HeadComponent::RegisterObject()
{
	GlobalObjectFactory::GetInstance()->RegisterFactory<HeadComponent>();
	
	S_ACCESSOR_PROPERTY("BrainWeight", GetBrainWeight, SetBrainWeight);
	S_ENUM_PROPERTY("HeadSize", m_sizeType);
	S_ENUM_ACCESSOR_PROPERTY("HeadSizeEnumGetter", GetSizeEnum, SetSizeEnum);

	S_ACCESSOR_PROPERTY("MyStruct", GetMyStruct, SetMyStruct);

	int a = 0;
	a++;
}

