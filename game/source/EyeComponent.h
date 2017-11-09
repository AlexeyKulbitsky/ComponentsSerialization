#ifndef EYE_COMPONENT_INCLUDE
#define EYE_COMPONENT_INCLUDE

#include <Component.h>

class EyeComponent : public Component
{
public:
	EyeComponent();
	virtual const char* GetName() const override;
	virtual void RegisterProperties() override;
	virtual void PrintDebugInfo() override;

	friend std::ostream& operator<<(std::ostream&, const EyeComponent&);

	int size = 0;
	float depth = 0.0f;
	std::string name;
};

#endif
