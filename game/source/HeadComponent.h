#ifndef HEAD_COMPONENT
#define HEAD_COMPONENT

#include <Component.h>
#include "EyeComponent.h"

class HeadComponent : public Component
{
	SHADOW_OBJECT(HeadComponent)
public:
	HeadComponent();
	virtual const char* GetName() const override;
	static void RegisterObject();

	EyeComponent* eyeComponent = nullptr;
};

#endif
