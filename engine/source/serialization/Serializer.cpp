#include "Serializer.h"
#include "Serializable.h"
#include "Property.h"
#include "GlobalObjectFactory.h"

#include <iostream>

void Serializer::Serialize(Serializable* serializable)
{
	auto properties = GlobalObjectFactory::GetInstance()->GetProperties(serializable->GetTypeName());
	if (!properties)
		return;

	for (auto prop : (*properties))
	{
		auto value = prop.second->GetValue(serializable);
		auto type = value.GetType();

		switch (type)
		{
		case ANY_SERIALIZABLE:
		{
			auto s = value.Get<Serializable*>();
			std::cout << s->GetTypeName() << std::endl;
		}
			break;
		default:
			break;
		}
	}
}