
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

struct MyFixture {
	MyFixture() {
		this->myFixtureValue = 3;
		BOOST_TEST_MESSAGE("fixture setUp");
	}

	~MyFixture() {
		BOOST_TEST_MESSAGE("fixture tearDown");
	}

	int myFixtureValue;
};

BOOST_AUTO_TEST_SUITE(testSuite1)

BOOST_FIXTURE_TEST_CASE(test_case1, MyFixture)
{
	BOOST_CHECK(myFixtureValue == 3);
}

BOOST_AUTO_TEST_SUITE_END()
