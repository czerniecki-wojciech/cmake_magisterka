
#include "gtest/gtest.h"

#include "../src/simple_calc.h"

::testing::Environment* globalFixture;

class MyGlobalTestFixture : public ::testing::Environment
{
public:
	virtual void SetUp()
	{
		sc.init();
	}

	virtual void TearDown()
	{}

	simple_calc sc;
};

class MyTestFixture : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		sc2.init();
	}

	virtual void TearDown()
	{

	}

	simple_calc sc2;
};

TEST_F(MyTestFixture, AdditionTest) {
	ASSERT_EQ(((MyGlobalTestFixture*)globalFixture)->sc.addInts(1, 1), 2);
	ASSERT_EQ(sc2.addInts(1, 1), 2);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	globalFixture = ::testing::AddGlobalTestEnvironment(new MyGlobalTestFixture());

	RUN_ALL_TESTS();

	return 0;
}