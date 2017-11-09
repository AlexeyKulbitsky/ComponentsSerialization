#include "Property.h"

Property::Property(int* dataPtr, const std::string& name)
	: m_type(Int)
	, m_dataPtr(dataPtr)
	, m_name(name)
{
}

Property::Property(float* dataPtr, const std::string& name)
	: m_type(Float)
	, m_dataPtr(dataPtr)
	, m_name(name)
{
}

Property::Property(bool* dataPtr, const std::string& name)
	: m_type(Boolean)
	, m_dataPtr(dataPtr)
	, m_name(name)
{
}


void Property::Set(const int value)
{
	if (m_type != Int)
		return;

	if (m_dataPtr)
	{
		auto intPtr = reinterpret_cast<int*>(m_dataPtr);
		*intPtr = value;
	}
}

void Property::Set(const float value)
{
	if (m_type != Float)
		return;

	if (m_dataPtr)
	{
		auto floatPtr = reinterpret_cast<float*>(m_dataPtr);
		*floatPtr = value;
	}
}

void Property::Set(const bool value)
{
	if (m_type != Boolean)
		return;

	if (m_dataPtr)
	{
		auto boolPtr = reinterpret_cast<bool*>(m_dataPtr);
		*boolPtr = value;
	}
}

const int Property::GetInt() const
{
	if (m_type != Int)
		return 0;

	auto intPtr = reinterpret_cast<int*>(m_dataPtr);
	return *intPtr;
}

const float Property::GetFloat() const
{
	if (m_type != Float)
		return 0.0f;

	auto floatPtr = reinterpret_cast<float*>(m_dataPtr);
	return *floatPtr;
}

const bool Property::GetBool() const
{
	if (m_type != Boolean)
		return false;

	auto boolPtr = reinterpret_cast<bool*>(m_dataPtr);
	return *boolPtr;
}

const std::string& Property::GetName() const
{
	return m_name;
}
