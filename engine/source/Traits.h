#ifndef TRAITS_INCLUDE
#define TRAITS_INCLUDE

#include <type_traits>

// template<typename T>
// struct PTraits
// {
// 	std::is_integral<T>::value;
// 	std::is_floating_point<T>::value;
// 
// 	std::is_const<T>::value;
// 
// 	std::is_reference<T>::value;
// 	std::is_pointer<T>::value;
// 
// 	std::is_base_of<Serializable, T>::value;
// 
// 	std::is_class<T>;
// };


namespace detail
{
	template<typename T, bool = std::is_class<T>::value, bool = std::is_pointer<T>::value>
	struct ClassTraits
	{
		using ArgumentType = const T&;
		using ResultType = const T&;

		static constexpr bool isConstant = std::is_const<T>::value;
		static constexpr bool isSerializable = std::is_base_of<Serializable, T>::value;
	};

	template<typename T>
	struct ClassTraits<T, true, true>
	{
		using ArgumentType = T;
		using ResultType = T;
	};

	template<typename T>
	struct ClassTraits<T, false, false>
	{
		using ArgumentType = T;
		using ResultType = T;
	};
}


template<typename T>
struct PTraits
{
	using ArgumentType = detail::ClassTraits<T>::ArgumentType;
	using ResultType = detail::ClassTraits<T>::ResultType;
};

class A
{
};

class B
{
public:
	int GetInt() const { return m_intValue; }


private:
	int m_intValue = 0;
};

template<typename ClassType, typename ValueType>
using Getter = ValueType ClassType::*() const;

Getter<B, int> g;


#endif
