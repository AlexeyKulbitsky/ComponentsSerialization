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

	void Set(EyeComponent* c) { eyeComponent = c; }
	const EyeComponent* Get() const { return eyeComponent; }

	void SetBrainWeight(const float weight) { m_brainWeight = weight; }
	float GetBrainWeight() const { return m_brainWeight; }

private:
	EyeComponent* eyeComponent = nullptr;
	float m_brainWeight = 2.3f;
};

#endif
