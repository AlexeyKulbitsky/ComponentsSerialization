#ifndef ANY_INCLUDE
#define ANY_INCLUDE

enum AnyType
{
	ANY_NOTYPE,
	ANY_INT,
	ANY_FLOAT,
	ANY_BOOL,
	ANY_STRING,

	ANY_SERIALIZABLE
};

class Serializable;

template<typename T> struct TypeToAnyType { enum { Type = ANY_NOTYPE }; };
template<> struct TypeToAnyType<int> { enum { Type = ANY_INT }; };
template<> struct TypeToAnyType<float> { enum { Type = ANY_FLOAT }; };
template<> struct TypeToAnyType<bool> { enum { Type = ANY_BOOL }; };
template<> struct TypeToAnyType<std::string> { enum { Type = ANY_STRING }; };
template<> struct TypeToAnyType<Serializable*> { enum { Type = ANY_SERIALIZABLE }; };

class Any
{
public:
	Any() {}

	template<typename T>
	Any(const T& value)
		: m_placeholder(new PlaceholderImpl<T>(value))
	{
	}

	~Any()
	{
		if (m_placeholder)
			delete m_placeholder;
	}

	template<typename T>
	const T& Get() const
	{
		return static_cast<PlaceholderImpl<T>*>(m_placeholder)->m_data;
	}

	template<typename T>
	void Set(const T& value)
	{
		static_cast<PlaceholderImpl<T>*>(m_placeholder)->m_data = value;
	}

	AnyType GetType() const 
	{ 
		if (!m_placeholder)
			return ANY_NOTYPE;
		return m_placeholder->GetType();
	}

private:
	class Placeholder
	{
	public:
		virtual ~Placeholder() {}
		virtual AnyType GetType() const { return ANY_NOTYPE; }
	};

	template<typename T> 
	class PlaceholderImpl : public Placeholder
	{
	public:
		PlaceholderImpl(const T& data) : m_data(data) {}
		virtual AnyType GetType() const override { return static_cast<AnyType>(TypeToAnyType<T>::Type); }
		T m_data;
		AnyType m_type;
	};

	Placeholder* m_placeholder = nullptr;
};

#endif
