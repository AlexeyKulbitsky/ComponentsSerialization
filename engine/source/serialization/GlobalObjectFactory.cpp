#include "GlobalObjectFactory.h"

GlobalObjectFactory* GlobalObjectFactory::GetInstance()
{
	static GlobalObjectFactory factory;
	return &factory;
}

Property* GlobalObjectFactory::GetProperty(const std::string& objectTypeName, const std::string& name)
{
	auto objectProperties = m_propertes.find(objectTypeName);
	if (objectProperties == m_propertes.end())
		return nullptr;

	auto property = objectProperties->second.find(name);
	if (property == objectProperties->second.end())
		return nullptr;

	return property->second;
}

std::map<std::string, Property*>* GlobalObjectFactory::GetProperties(const std::string& objectTypeName)
{
	auto objectProperties = m_propertes.find(objectTypeName);
	if (objectProperties == m_propertes.end())
		return nullptr;

	return &objectProperties->second;
}

Serializable* GlobalObjectFactory::CreateObject(const std::string& type)
{
	auto it = m_factories.find(type);
	if (it == m_factories.end())
		return nullptr;

	return it->second->CreateObject();
}

std::vector<std::string> GlobalObjectFactory::GetObjectTypes() const
{
	std::vector<std::string> result;

	for (auto factory : m_factories)
	{
		result.push_back(factory.first);
	}

	return result;
}