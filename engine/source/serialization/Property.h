#ifndef PROPERTY_INCLUDE
#define PROPERTY_INCLUDE

#include "../Globals.h"
#include "../Variant.h"
#include "Serializable.h"

#include <type_traits>

class Property
{
public:
	Property(const std::string& name) : m_name(name) {}
	virtual void SetValue(Serializable* object, const Variant& value) = 0;
	virtual Variant GetValue(Serializable* object) = 0;
	const std::string& GetName() const;

private:
	std::string m_name = "noname";
};

template<typename ClassType, typename FieldType, typename BaseFieldType = FieldType>
class PropertyImpl : public Property
{
public:
	using FieldPtr = FieldType ClassType::*;

	PropertyImpl(FieldPtr ptr, const std::string& name) : Property(name), m_ptr(ptr) {}
	virtual void SetValue(Serializable* object, const Variant& value) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		concreteClass->*m_ptr = static_cast<FieldType>(value.Get<BaseFieldType>());
	}
	virtual Variant GetValue(Serializable* object) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		return Variant(concreteClass->*m_ptr);
	}

private:
	FieldPtr m_ptr = nullptr;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*template<typename T, bool = std::is_scalar<T>::value, bool = std::is_pointer<T>::value>
struct ParamTypeTrait
{
	using ParamType = T;
	using ReturnType = T;
};

template<typename T>
struct ParamTypeTrait<T, false, false>
{
	using ParamType = const T&;
	using ReturnType = const T&;
};

template<typename ClassType, typename ValueType, typename ParamTrait, typename BaseValueType = ValueType>
class AccessorPropertyImpl : public Property
{
public:
	using GetterPtr = typename ParamTrait::ReturnType (ClassType::*)() const;
	using SetterPtr = void (ClassType::*) (typename ParamTrait::ParamType);

	AccessorPropertyImpl(GetterPtr getter, SetterPtr setter, const std::string& name) 
		: Property(name)
		, m_getter(getter)
		, m_setter(setter) {}

	virtual void SetValue(Serializable* object, const Variant& value) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		(concreteClass->*m_setter)(static_cast<ValueType>(value.Get<BaseValueType>()));
	}
	virtual Variant GetValue(Serializable* object) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		return Variant((concreteClass->*m_getter)());
	}

private:
	GetterPtr m_getter;
	SetterPtr m_setter;
};*/

#define S_FIELD_PROPERTY(name, FieldType, field) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(new PropertyImpl<ClassType, FieldType>(&ClassType::field, name))

#define S_FIELD_PROPERTY_EXT(name, FieldType, BaseFieldType, field) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(new PropertyImpl<ClassType, FieldType, BaseFieldType>(&ClassType::field, name))

//#define S_ACCESSOR_PROPERTY(name, FieldType, Getter, Setter) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(new AccessorPropertyImpl<ClassType, FieldType, ParamTypeTrait<FieldType>>(&ClassType::Getter, &ClassType::Setter, name))

//#define S_ACCESSOR_PROPERTY_EXT(name, FieldType, BaseFieldType, Getter, Setter) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(new AccessorPropertyImpl<ClassType, FieldType, ParamTypeTrait<FieldType>, BaseFieldType>(&ClassType::Getter, &ClassType::Setter, name))


template<typename ClassType, typename ReturnType, typename ArgumentType>
class AccessorPropertyImplExt : public Property
{
public:
	using GetterPtr = ReturnType(ClassType::*)() const;
	using SetterPtr = void (ClassType::*) (ArgumentType);

	using NoPtrReturnType = std::remove_pointer<ReturnType>;
	using NoPtrArgumentType = std::remove_pointer<ArgumentType>;

	static_assert(std::is_same<NoPtrReturnType, NoPtrReturnType>::value, 
				  "The return and argument type differs from each other");

	template<typename T, bool = std::is_base_of<Serializable, T>::value>
	struct BaseType
	{
		using Type = T;
	};

	template<typename T>
	struct BaseType<T, true>
	{
		using Type = Serializable*;
	};

	AccessorPropertyImplExt(GetterPtr getter, SetterPtr setter, const std::string& name)
		: Property(name)
		, m_getter(getter)
		, m_setter(setter) {}

	virtual void SetValue(Serializable* object, const Variant& value) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		(concreteClass->*m_setter)((ArgumentType)value.Get<BaseType<std::remove_pointer_t<ReturnType>>::Type>());
	}
	virtual Variant GetValue(Serializable* object) override
	{
		ClassType* concreteClass = static_cast<ClassType*>(object);
		return Variant((BaseType<std::remove_pointer_t<ReturnType>>::Type)(concreteClass->*m_getter)());
	}

private:
	GetterPtr m_getter;
	SetterPtr m_setter;
};

template<typename ClassType, typename ReturnType>
using Getter = ReturnType (ClassType::*)() const;
template<typename ClassType, typename ArgumentType>
using Setter = void (ClassType::*)(ArgumentType);

template<typename ClassType, typename ReturnType, typename ArgumentType>
Property* CreateProperty(Getter<ClassType, ReturnType> getter, Setter<ClassType, ArgumentType> setter, const std::string& name)
{
	return new AccessorPropertyImplExt<ClassType, ReturnType, ArgumentType>(getter, setter, name);
}

#define S_ACCESSOR_PROPERTY(name, Getter, Setter) GlobalObjectFactory::GetInstance()->RegisterProperty<ClassType>(CreateProperty(&ClassType::Getter, &ClassType::Setter, name))


//////////////////////////////////////////////////////////////



#endif
