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

	// Close library
	FreeLibrary(libraryHandle);

	return 0;
}