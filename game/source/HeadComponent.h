#ifndef HEAD_COMPONENT
#define HEAD_COMPONENT

#include <Component.h>
#include "EyeComponent.h"

class HeadComponent : public Component
{
	SHADOW_OBJECT(HeadComponent)
public:
	enum class SizeType
	{
		Small = 0,
		Medium,
		Big,
		Extra
	};

	HeadComponent();
	static void RegisterObject();

	void SetBrainWeight(const float weight) { m_brainWeight = weight; }
	float GetBrainWeight() const { return m_brainWeight; }

	void SetSizeEnum(const SizeType size) { m_sizeType = size; }
	SizeType GetSizeEnum() const { return m_sizeType; }

	SizeType m_sizeType = SizeType::Small;

private:
	float m_brainWeight = 2.3f;
};

#endif
