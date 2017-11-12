#ifndef GLOBAL_OBJECT_FACTORY
#define GLOBAL_OBJECT_FACTORY

//#include "Serializable.h"
#include "Property.h"
#include "../Globals.h"

class ObjectFactory
{
public:
	virtual Serializable* CreateObject() = 0;
	const std::string& GetName() { return m_name; }

protected:
	std::string m_name;
};

template<typename T>
class ObjectFactoryImpl : public ObjectFactory
{
public:
	ObjectFactoryImpl()
	{
		m_name = T::GetTypeName();
	}
	virtual Serializable* CreateObject() override { return new T(); }
};

class GlobalObjectFactory
{
public:
	static GlobalObjectFactory* GetInstance();

	template<typename T> 
	void RegisterFactory()
	{
		ObjectFactory* factory = new ObjectFactoryImpl<T>();
		m_factories[factory->GetName()] = factory;
	}

	template<typename T>
	void RegisterProperty(Property* property)
	{
		m_propertes[T::GetTypeName()][property->GetName()] = property;
	}

	Property* GetProperty(const std::string& objectTypeName, const std::string& name);
	template<typename T>
	Property* GetProperty(const std::string& name)
	{
		return GetProperty(T::GetTypeName(), name);
	}

	std::map<std::string, Property*>* GetProperties(const std::string& objectTypeName);
	template<typename T>
	std::map<std::string, Property*>* GetProperties()
	{
		return GetProperties(T::GetTypeName());
	}

	Serializable* CreateObject(const std::string& type);
	std::vector<std::string> GetObjectTypes() const;

private:
	std::map<std::string, ObjectFactory*> m_factories;
	std::map<std::string, std::map<std::string, Property*>> m_propertes;
};

#endif
