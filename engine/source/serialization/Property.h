#ifndef PROPERTY_INCLUDE
#define PROPERTY_INCLUDE

#include "../Globals.h"
#include "../Any.h"
#include "Serializable.h"

class Property
{
public:
	Property(const std::string& name) : m_name(name) {}
	virtual void SetValue(Serializable* object, const Any& value) = 0;
	virtual Any GetValue(Serializable* object) = 0;
	const std::string& GetName() const;

private:
	std::string m_name = "noname";
};

template<typename ClassType, typename FieldType>
class PropertyImpl : public Property
{
public:
	using FieldPtr = FieldType ClassType::*;

	PropertyImpl(FieldPtr ptr, const std::string& name) : Property(name), m_ptr(ptr) {}
	virtual void SetValue(Serializable* object, const Any& value) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		concreteClass->*m_ptr = value.Get<FieldType>();
	}
	virtual Any GetValue(Serializable* object) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		return Any(concreteClass->*m_ptr);
	}

private:
	FieldPtr m_ptr = nullptr;
};

template<typename T>
struct ParamTypeTrait
{
	using ParamType = const T&;
	using ReturnType = const T&;
};

template<>
struct ParamTypeTrait<int>
{
	using ParamType = int;
	using ReturnType = int;
};

template<>
struct ParamTypeTrait<float>
{
	using ParamType = float;
	using ReturnType = float;
};

template<typename ClassType, typename ValueType, typename ParamTrait>
class AccessorPropertyImpl : public Property
{
public:
	using GetterPtr = typename ParamTrait::ReturnType (ClassType::*)() const;
	using SetterPtr = void (ClassType::*) (typename ParamTrait::ParamType);

	AccessorPropertyImpl(GetterPtr getter, SetterPtr setter, const std::string& name) 
		: Property(name)
		, m_getter(getter)
		, m_setter(setter) {}

	virtual void SetValue(Serializable* object, const Any& value) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		(concreteClass->*m_setter)(value.Get<ValueType>());
	}
	virtual Any GetValue(Serializable* object) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		return Any((concreteClass->*m_getter)());
	}

private:
	GetterPtr m_getter;
	SetterPtr m_setter;
};

#define S_FIELD_PROPERTY(name, FieldType, field) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(new PropertyImpl<ClassType, FieldType>(&ClassType::field, name))

#define S_ACCESSOR_PROPERTY(name, FieldType, Getter, Setter) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(new AccessorPropertyImpl<ClassType, FieldType, ParamTypeTrait<FieldType>>(&ClassType::Getter, &ClassType::Setter, name))

#endif
