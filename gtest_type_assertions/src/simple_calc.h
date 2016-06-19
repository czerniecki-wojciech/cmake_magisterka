#pragma once
class simple_calc
{
public:
	template<typename T>
	T add(T a, T b)
	{
		return a + b;
	}

	simple_calc();
	~simple_calc();
};

