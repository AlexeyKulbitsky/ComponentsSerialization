#ifndef PROPERTY_INCLUDE
#define PROPERTY_INCLUDE

#include "../Globals.h"
#include "Serializable.h"

class Property
{
public:
	Property(const std::string& name) : m_name(name) {}
	virtual void SetValue(Serializable* object, int value) {}
	const std::string& GetName() const;

private:
	std::string m_name = "noname";
};

template<typename ClassType, typename FieldType>
class PropertyImpl : public Property
{
public:
	PropertyImpl(FieldType ClassType::* ptr, const std::string& name) : Property(name), m_ptr(ptr) {}
	virtual void SetValue(Serializable* object, int value) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		(*concreteClass).*m_ptr = value;
	}

private:
	FieldType ClassType::* m_ptr = nullptr;
};

#endif
