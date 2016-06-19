
#include "gtest/gtest.h"

#include "../src/simple_calc.h"

class CalcFixture : public ::testing::Test
{
protected:
	simple_calc sc;
};

template<typename T1, typename T2>
void testType(T2 a) {
	::testing::StaticAssertTypeEq<T1, T2>();
}

template<typename T1, typename T2>
void areTheSameType(T1 a, T2 b) {
	::testing::StaticAssertTypeEq<T1, T2>();
}

TEST_F(CalcFixture, intTest)
{
	int a = 1;
	int b = 2;
	double c = 3.0;
	auto d = sc.add(a, b);

	areTheSameType(a, b);
	//areTheSameType(a, c); // will throw compilation error
	testType<int>(d);
};

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}
