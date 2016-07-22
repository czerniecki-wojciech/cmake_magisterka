#include "PrintingComponent.h"

void PrintingComponent::printString(const char* string)
{
	myOutputStream << string;
}