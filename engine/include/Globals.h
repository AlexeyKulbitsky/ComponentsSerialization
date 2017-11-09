#ifndef GLOBALS_INCLUDE
#define GLOBALS_INCLUDE

#include <vector>
#include <map>
#include <functional>

#define SHARED_LIB

#if defined (SHARED_LIB)
#define MY_TEST_API __declspec(dllexport)
#else
#define MY_TEST_API __declspec(dllimport)
#endif


#endif
