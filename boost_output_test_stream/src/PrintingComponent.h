#ifndef PrintingComponent_H
#define PrintingComponent_H

#include<iostream>

class PrintingComponent
{
private:
	std::ostream& myOutputStream;
public:
	PrintingComponent(std::ostream& stream) : myOutputStream(stream) {}
	~PrintingComponent() {}

	void printString(const char* string);
};

#endif