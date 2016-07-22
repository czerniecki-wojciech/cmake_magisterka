#include "simple_calc.h"

//funkcja wymagana przed uruchomieniem dzialania metody addInts
void simple_calc::init()
{
	initialized = true;
}

//dodawanie liczb calkowitych
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

//konstruktor
simple_calc::simple_calc()
	: lastSum(0)
	, initialized(false)
{}