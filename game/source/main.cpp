#include "HeadComponent.h"
#include <serialization/GlobalObjectFactory.h>


#include <iostream>





template<typename T>
T adder(T v)
{
	return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args)
{
	return first + adder(args...);
}
int sum = adder(1, 4, 5, 6);

/////////// TUPLE

namespace tuple_test
{
	template<typename... Args>
	struct Tuple;

	template<typename Head, typename... Tail>
	struct Tuple<Head, Tail...> : Tuple<Tail...>
	{
		Tuple(Head h, Tail... tail) : Tuple<Tail...>(tail...), head(h) {}
		using ValueType = Head;
		Head head;
	};

	template<>
	struct Tuple<> {};


	template<size_t I, typename Head, typename... Tail>
	struct Getter
	{
		typedef typename Getter<I - 1, Tail...>::ReturnType ReturnType;
		static ReturnType Get(Tuple<Head, Tail...> tuple)
		{
			return Getter<I - 1, Tail...>::Get(tuple);
		}
	};

	template<typename Head, typename... Tail>
	struct Getter<0, Head, Tail...>
	{
		typedef typename Tuple<Head, Tail...>::ValueType ReturnType;
		static ReturnType Get(Tuple<Head, Tail...> tuple)
		{
			return tuple.head;
		}
	};

	template<size_t I, typename Head, typename... Tail>
	typename Getter<I, Head, Tail...>::ReturnType
		Get(Tuple<Head, Tail...> tuple)
	{
		return Getter<I, Head, Tail...>::Get(tuple);
	}
}


//namespace 


enum class MyEnum
{
	First,
	Second,
	Third
};

template <typename ... T> void null(T...) {}

template <typename ... T>
constexpr size_t countLength(T ... args)
{
	null(args...); //kill warnings
	return sizeof...(args);
}


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

	tuple_test::Tuple<int, double, int> t(12, 2.34, 89);
	std::cout << tuple_test::Get<0>(t) << " " << tuple_test::Get<1>(t) << " " << tuple_test::Get<2>(t) << std::endl;

	bool isEnum = std::is_enum<MyEnum>::value;
	auto m = std::numeric_limits<enum class MyEnum>::max();
	MyEnum e = MyEnum::First;
	auto enumLength = countLength(e);

	int a = 0;
	a++;

	return 0;
}