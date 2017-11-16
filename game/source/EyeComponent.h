#ifndef EYE_COMPONENT_INCLUDE
#define EYE_COMPONENT_INCLUDE

#include <Component.h>

class EyeComponent : public Component
{
	SHADOW_OBJECT(EyeComponent)
public:
	EyeComponent();
	static void RegisterObject();
	virtual void PrintDebugInfo() override;

	int size = 0;
	float depth = 0.0f;
	std::string name;

	void SetAge(int age) { m_age = age; }
	int GetAge() const { return m_age; }

private:
	int m_age = 0;
};

#endif
