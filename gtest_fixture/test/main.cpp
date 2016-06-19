
#include "gtest/gtest.h"

#include "../src/simple_calc.h"

class MyTestFixture : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		sc.init();
	}

	virtual void TearDown()
	{

	}

	simple_calc sc;
};

TEST_F(MyTestFixture, AdditionTest) {
	ASSERT_EQ(sc.addInts(1, 1), 2);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}