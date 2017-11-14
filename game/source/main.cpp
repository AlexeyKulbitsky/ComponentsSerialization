#include "HeadComponent.h"
#include <serialization/GlobalObjectFactory.h>

int main()
{
	EyeComponent::RegisterObject();
	HeadComponent::RegisterObject();

	EyeComponent* eyeComponent = new EyeComponent();
	eyeComponent->name = "RightEye";
	eyeComponent->Serialize();

	HeadComponent* headComponent = new HeadComponent();

	auto factory = GlobalObjectFactory::GetInstance();
	auto headComponentProperties = factory->GetProperties<HeadComponent>();

	auto eyeComponentProperty = headComponentProperties->at("EyeComponent");
	eyeComponentProperty->SetValue(headComponent, eyeComponent);

	headComponent->Serialize();

	int a = 0;
	a++;

	return 0;
}