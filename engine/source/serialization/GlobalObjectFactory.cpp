#include "GlobalObjectFactory.h"

GlobalObjectFactory* GlobalObjectFactory::GetInstance()
{
	static GlobalObjectFactory factory;
	return &factory;
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