#include "simple_calc.h"

void simple_calc::init()
{
	initialized = true;
}

int simple_calc::addInts(int a, int b)
{
	if (initialized)
	{
		return a + b;
	}
	else {
		return 0;
	}
}


simple_calc::simple_calc()
{
	initialized = false;
}


simple_calc::~simple_calc()
{
}
