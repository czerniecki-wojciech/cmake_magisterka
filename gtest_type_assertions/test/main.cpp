#include "gtest/gtest.h"
#include "../src/simple_calc.h"

//definicja fixtury
class CalcFixture : public ::testing::Test
{
protected:
	simple_calc sc;
};

//funkcja sprawdzajaca czy zmienna posiada dany typ
template<typename T1, typename T2>
void testType(T2 a) {
	::testing::StaticAssertTypeEq<T1, T2>();
}

//funkcja sprawdzajaca czy zmienne sa takiego samego typu
template<typename T1, typename T2>
void areTheSameType(T1 a, T2 b) {
	::testing::StaticAssertTypeEq<T1, T2>();
}

//definicja testu wykorzystujacego fixture
TEST_F(CalcFixture, intTest)
{
	//przykladowe dane 
	int a = 1;
	int b = 2;
	double c = 3.0;
	auto d = sc.add(a, b);

	//sprawdzenie czy a i b s¹ tego samego typu
	areTheSameType(a, b);
	//sprawdzenie czy d jest typu int
	testType<int>(d);
};

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}