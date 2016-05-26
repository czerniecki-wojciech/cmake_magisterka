// example000.cpp : Defines the entry point for the console application.
//

#include "simple_calc.h"


int main()
{
	simple_calc sc;
	sc.addInts(1, 2);

	if (sc.addInts(1, 2) != 3)
	{
		int b = 3;
		int a = 3 / (b-b);
	}

    return 0;
}

