#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

//definicja fixtury
class MyFixture {
public:
	MyFixture() { //konstruktor odpalany przed rozpoczeciem testu
		this->myFixtureValue = 3;
	}

	~MyFixture() {
		//destruktor odpalany po tescie
	}
	//przykladowe dane
	int myFixtureValue;
};
//zdefiniowanie globalnej fixtury
BOOST_GLOBAL_FIXTURE(MyFixture);
//definicja grupy testow
BOOST_AUTO_TEST_SUITE(testSuite1)
//definicja testu
BOOST_AUTO_TEST_CASE(test_case1)
{
	//cialo testu
}
//koniec definicji grupy testów
BOOST_AUTO_TEST_SUITE_END()