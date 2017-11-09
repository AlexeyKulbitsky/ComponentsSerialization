#ifndef GLOBAL_OBJECT_FACTORY
#define GLOBAL_OBJECT_FACTORY

#include "Serializable.h"
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
		m_name = typeid(T).name();
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

	Serializable* CreateObject(const std::string& type);
	std::vector<std::string> GetObjectTypes() const;

private:
	std::map<std::string, ObjectFactory*> m_factories;
};

#endif
