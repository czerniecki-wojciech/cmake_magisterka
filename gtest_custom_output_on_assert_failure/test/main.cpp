
#include "gtest/gtest.h"
#include <iostream>
#include <string>

//definicje klas posiadajacych metode wypisujaca wartosc zmiennej logicznej przechowywanej w klasie
class MyFirstClass
{
public:
	MyFirstClass() : a(false) {}
	bool a;
    std::string createStringRepresentation() const
	{
		return std::string("Current state of MyFirstClass.a = ") + std::string(a ? "true" : "false");
	}
};

class MySecondClass
{
public:
	bool b;
	MySecondClass() : b(false) {}
	std::string createStringRepresentation() const
	{
		return std::string("Current state of MySecondClass.b = ") + std::string(b ? "true" : "false");
	}
};

class MyThirdClass
{
public:
	bool c;
	MyThirdClass() : c(false) {}
	std::string createStringRepresentation() const
	{
		return std::string("Current state of MyThirdClass.c = ") + std::string(c ? "true" : "false");
	}
};

//definicja operator wypisania na strumien werjsciowy dla zdefiniowanych klas

std::ostream& operator<<(std::ostream& os, const MyFirstClass& mfc)
{
	return os << mfc.createStringRepresentation();
}

void PrintTo(const MySecondClass& msc, std::ostream* os)
{
	*os << msc.createStringRepresentation();
}

std::ostream& operator<<(std::ostream& os, const MyThirdClass& mtc)
{
	return os << "operator << " + mtc.createStringRepresentation();
}

void PrintTo(const MyThirdClass& mtc, std::ostream* os)
{
	*os << "PrintTo " + mtc.createStringRepresentation();
}
//definicja testu
TEST(AssertLevelTest, NonFatal) {
	//obiekty wczesniej zdefiniowanych klas
	MyFirstClass first;
	MySecondClass second;
	MyThirdClass third;
	//wywolanie operatora wypisania w momencie niepowodzenia porownania
	EXPECT_EQ(first.a, true) << ::testing::PrintToString(first);
	EXPECT_EQ(second.b, true) << ::testing::PrintToString(second);
	EXPECT_EQ(third.c, true) << ::testing::PrintToString(third);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}