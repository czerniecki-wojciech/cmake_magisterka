#include "gtest/gtest.h"
#include "../src/simple_calc.h"

//definicja fixtury
class SimpleCalcTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		sc.init();
	}

	virtual void TearDown()
	{}

	simple_calc sc;
};
//definicja testu wykorzystujacego fixture
TEST_F(SimpleCalcTest, PrivateMemberTest) {
	sc.addInts(1, 1);
	ASSERT_EQ(sc.lastSum, 2); //testowanie zmiennej prywatnej klasy sc
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
