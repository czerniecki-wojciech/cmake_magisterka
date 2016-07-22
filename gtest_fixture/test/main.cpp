#include "gtest/gtest.h"

#include "../src/simple_calc.h"

//definicja fixtury
class MyTestFixture : public ::testing::Test
{
protected:
	//metoda wywolywana przed rozpoczeciem testu
	virtual void SetUp()
	{
		sc.init();
	}

	//metoda wywolywana po zakonczeniu testu
	virtual void TearDown()
	{

	}

	//przykladowe dane
	simple_calc sc;
};

//definicja testu wykorzystujacego zdefiniowana fixture
TEST_F(MyTestFixture, AdditionTest) {
	//wykorzystanie klasy dostepnej w fixturze
	ASSERT_EQ(sc.addInts(1, 1), 2);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}