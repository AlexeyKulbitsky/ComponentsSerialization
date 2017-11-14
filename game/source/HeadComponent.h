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

	void SetEyeComponent(EyeComponent* c) { eyeComponent = c; }
	EyeComponent* GetEyeComponent() const { return eyeComponent; }

	void Set(EyeComponent* c) { eyeComponent = c; }
	const EyeComponent* Get() const { return eyeComponent; }

private:
	EyeComponent* eyeComponent = nullptr;
};

#endif
