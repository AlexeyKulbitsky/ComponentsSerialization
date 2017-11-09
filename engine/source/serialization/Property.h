#ifndef PROPERTY_INCLUDE
#define PROPERTY_INCLUDE

#include "../Globals.h"

class Property
{
public:
	enum Type
	{
		Int,
		Float,
		Boolean,

		Unknown
	};

	Property(int* dataPtr, const std::string& name);
	Property(float* dataPtr, const std::string& name);
	Property(bool* dataPtr, const std::string& name);
	
	void Set(const int value);
	void Set(const float value);
	void Set(const bool value);

	const int GetInt() const;
	const float GetFloat() const;
	const bool GetBool() const;

	const std::string& GetName() const;

	Type GetType() const { return m_type; }

private:
	Type m_type = Unknown;
	void* m_dataPtr = nullptr;
	std::string m_name = "noname";
};

#endif
