#include "simple_calc.h"

void simple_calc::init()
{
	initialized = true;
}

int simple_calc::addInts(int a, int b)
{
	if (initialized)
	{
		lastSum = a + b;
		return lastSum;
	}
	else {
		return 0;
	}
}


simple_calc::simple_calc()
	: lastSum(0)
	, initialized(false)
{}


simple_calc::~simple_calc()
{
}
