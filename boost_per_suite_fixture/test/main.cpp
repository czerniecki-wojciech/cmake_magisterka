#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

//definicja fixtury
struct MyFixture {
	MyFixture() {//konstruktor odpalany przed rozpoczeciem testu
		this->myFixtureValue = 3;
	}

	~MyFixture() {
		//destruktor odpalany po tescie
	}
	//przykladowe dane
	int myFixtureValue;
};

//definicja grupy testow wykorzystujacych zdefiniowana fixture
BOOST_FIXTURE_TEST_SUITE(testSuite1, MyFixture)
//definicja testu
BOOST_AUTO_TEST_CASE(test_case1)
{
	//porowanie zmiennej dostepnej w fixturze
	BOOST_CHECK(myFixtureValue == 3);
}
//koniec definicji grupy testow
BOOST_AUTO_TEST_SUITE_END()
