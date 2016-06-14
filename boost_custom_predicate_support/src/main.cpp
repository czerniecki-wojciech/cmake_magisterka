
#include <iostream>
#include "PrintingComponent.h"

int main()
{
	PrintingComponent pc(std::cout);
	pc.printString("test string");

    return 0;
}

