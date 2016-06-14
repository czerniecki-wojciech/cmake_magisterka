
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testSuite1)

BOOST_AUTO_TEST_CASE(test_case1)
{
	BOOST_TEST_MESSAGE("\n***   I'm inside test_case1   ***\n");
	BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()
