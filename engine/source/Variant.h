#ifndef VARIANT_INCLUDE
#define VARIANT_INCLUDE

#include "Globals.h"

enum VariantType
{
	VAR_NOTYPE,
	VAR_INT,
	VAR_FLOAT,
	VAR_BOOL,
	VAR_STRING,
	VAR_SERIALIZABLE
};

class Serializable;

struct SerializableRef
{
	SerializableRef(Serializable* s) : ref(s) {}
	Serializable* ref;
};

class Variant
{
public:
	Variant(int value)
		: m_type(VAR_NOTYPE)
	{
		*this = value;
	}

	Variant(float value)
		: m_type(VAR_NOTYPE)
	{
		*this = value;
	}

	Variant(bool value)
		: m_type(VAR_NOTYPE)
	{
		*this = value;
	}

	Variant(const std::string& value)
		: m_type(VAR_NOTYPE)
	{
		*this = value;
	}

	Variant(Serializable* value)
		: m_type(VAR_NOTYPE)
	{
		*this = value;
	}

	Variant& operator=(int value)
	{
		SetType(VAR_INT);
		m_int = value;
		return *this;
	}

	Variant& operator=(float value)
	{
		SetType(VAR_FLOAT);
		m_float = value;
		return *this;
	}

	Variant& operator=(bool value)
	{
		SetType(VAR_BOOL);
		m_bool = value;
		return *this;
	}

	Variant& operator=(const std::string& value)
	{
		SetType(VAR_STRING);
		*reinterpret_cast<std::string*>(m_ptr) = value;
		return *this;
	}

	Variant& operator=(Serializable* value)
	{
		SetType(VAR_SERIALIZABLE);
		m_ptr = value;
		return *this;
	}

	int GetInt() const;
	float GetFloat() const;
	bool GetBool() const;
	const std::string& GetString() const;
	Serializable* GetSerializable() const;

	template<typename T>
	T Get() const;// { return T(); }

	VariantType GetType() const { return m_type; }

private:
	void SetType(VariantType type);

	union
	{
		float m_float;
		int m_int;
		bool m_bool;
		void* m_ptr;
	};

	VariantType m_type = VAR_NOTYPE;
};

template<> int Variant::Get<int>() const;
template<> float Variant::Get<float>() const;
template<> bool Variant::Get<bool>() const;
template<> std::string Variant::Get<std::string>() const;
template<> Serializable* Variant::Get<Serializable*>() const;

#endif
