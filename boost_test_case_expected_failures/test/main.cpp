
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testSuite1)

int expectedFailures = 1;

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_case1, 1);

BOOST_AUTO_TEST_CASE(test_case1)
{
	BOOST_CHECK(true == false);
	BOOST_CHECK(2 == 2);
}

BOOST_AUTO_TEST_SUITE_END()
