#include "gtest/gtest.h"

#include "../src/simple_calc.h"

//wskaznik do globalnej fixtury
::testing::Environment* globalFixture;

//definicja fixtury
class MyGlobalTestFixture : public ::testing::Environment
{
public:
	//metoda wywolywana przed rozpoczeciem testu
	virtual void SetUp()
	{
		sc.init();
	}

	//metoda wywolywana po zakonczeniu testu
	virtual void TearDown()
	{}

	//przykladowe dane
	simple_calc sc;
};

//definicja testu 
TEST(TestSuite, AdditionTest) {
	//wykorzystanie klasy dostepnej w fixturze
	ASSERT_EQ(((MyGlobalTestFixture*)globalFixture)->sc.addInts(1, 1), 2);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	//rejestracja globalnej fixtury i przypisanie jej do ogolnodostepnego wskaznika
	globalFixture = ::testing::AddGlobalTestEnvironment(new MyGlobalTestFixture());

	RUN_ALL_TESTS();

	return 0;
}