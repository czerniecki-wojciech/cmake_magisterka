
#include "gtest/gtest.h"

#include "../src/simple_calc.h"


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

TEST_F(SimpleCalcTest, PrivateMemberTest) {
	sc.addInts(1, 1);
	ASSERT_EQ(sc.lastSum, 2);
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
