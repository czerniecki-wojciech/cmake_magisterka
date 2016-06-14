
#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE master test suite name

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testSuite1)

BOOST_AUTO_TEST_CASE(test_case1)
{
	BOOST_CHECK(true == true);
}
BOOST_AUTO_TEST_CASE(test_case2)
{
	BOOST_CHECK(true == true);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testSuite2)

BOOST_AUTO_TEST_CASE(test_case3)
{
	BOOST_CHECK(true == true);
}

BOOST_AUTO_TEST_SUITE_END()
