
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <vector>

typedef std::vector<int> intVector;

BOOST_TEST_DONT_PRINT_LOG_VALUE(intVector);

BOOST_AUTO_TEST_SUITE(testSuite1)

BOOST_AUTO_TEST_CASE(test_case1)
{
	intVector iv1 = { 1, 2 };
	intVector iv2 = { 4, 3 };
	BOOST_CHECK_EQUAL(1, 3);
	BOOST_CHECK_EQUAL(iv1, iv2);
}

BOOST_AUTO_TEST_SUITE_END()
