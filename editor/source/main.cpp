#include <Entity.h>

#include <Windows.h>
#include <iostream>



int main()
{
	// Try to import library
	HINSTANCE libraryHandle = LoadLibrary("Engine.dll");
	if (!libraryHandle)
	{
		std::cout << "Can not load DLL" << std::endl;
		return -1;
	}

	auto functionPointer = GetProcAddress(libraryHandle, "CreateEntity");
	if (!functionPointer)
	{
		std::cout << "Can not get function pointer" << std::endl;
		return -1;
	}

	auto result = reinterpret_cast<Entity*>(functionPointer());


	return 0;
}