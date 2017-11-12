#ifndef ANY_INCLUDE
#define ANY_INCLUDE

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

private:
	class Placeholder
	{
	public:
		virtual ~Placeholder() {}
	};

	template<typename T> 
	class PlaceholderImpl : public Placeholder
	{
	public:
		PlaceholderImpl(const T& data) : m_data(data) {}
		T m_data;
	};

	Placeholder* m_placeholder = nullptr;
};

#endif
