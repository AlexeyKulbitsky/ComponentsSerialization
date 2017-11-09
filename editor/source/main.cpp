#include <ComponentFactory.h>
#include <serialization/GlobalObjectFactory.h>
#include <Component.h>

#include <Windows.h>
#include <iostream>


int main()
{
	// Try to import library
	HINSTANCE libraryHandle = LoadLibrary("Game.dll");
	if (!libraryHandle)
	{
		std::cout << "Can not load DLL" << std::endl;
		return -1;
	}

	auto functionPointer = GetProcAddress(libraryHandle, "GetFactory");
	if (!functionPointer)
	{
		std::cout << "Can not get function pointer" << std::endl;
		return -1;
	}

	// Try to get component factory
	auto factory = reinterpret_cast<ComponentFactory*>(functionPointer());
	if (!factory)
	{
		std::cout << "Can not get component factory" << std::endl;
		return -1;
	}

	// Local component factory test
	size_t componentsCount = factory->GetComponentCount();
	for (size_t i = 0; i < componentsCount; ++i)
	{
		auto component = factory->GetComponent(i);
		std::cout << "Component : " << component->GetName() << std::endl;
		auto properties = component->GetProperties();
		for (auto prop : properties)
		{
			prop->Set(2334.0f);
		}
	}

	// Global object factory test
	auto globalFactoryGetter = GetProcAddress(libraryHandle, "GetGlobalFactory");
	if (!globalFactoryGetter)
	{
		std::cout << "Can not get function pointer" << std::endl;
		return -1;
	}
	auto globalFactory = reinterpret_cast<GlobalObjectFactory*>(globalFactoryGetter());
	if (!globalFactory)
	{
		std::cout << "Can not get global factory" << std::endl;
		return -1;
	}

	auto objectTypeList = globalFactory->GetObjectTypes();
	std::cout << "Registered Types:" << std::endl;
	for (auto objectType : objectTypeList)
	{
		// Print object type and try to create instance of each object
		std::cout << objectType << std::endl;
		auto instance = globalFactory->CreateObject(objectType);
		if (instance)
			delete instance;
	}

	auto printDebugInfoFnPtr = GetProcAddress(libraryHandle, "PrintDebugInfo");
	if (printDebugInfoFnPtr)
	{
		printDebugInfoFnPtr();
	}

	return 0;
}