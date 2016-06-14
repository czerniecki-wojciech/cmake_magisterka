
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testSuite1)

int div(int a)
{
	return 30 / (3 - a);
}

BOOST_AUTO_TEST_CASE(test_case1)
{
	for (int i = 0; i < 5; ++i)
	{
		BOOST_TEST_CHECKPOINT("Checkpoint for i = " << i);
		div(i);
		BOOST_CHECK_EQUAL(1.000000000f, 1.0000000001f);
	}
}

BOOST_AUTO_TEST_SUITE_END()
