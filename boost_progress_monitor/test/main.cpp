
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "../src/simple_calc.h"

#include <iostream>

const int TOTAL_TEST_CASES = 100000;

void testFunction() {
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
	BOOST_CHECK(1 == 1);
}

bool init_unit_test_suite()
{
	BOOST_TEST_MESSAGE("\n\nPlease use this test file with --show_progress=yes --log_level=nothing\n\n");

	boost::unit_test::test_suite* ts1 = BOOST_TEST_SUITE("Test Suite 1");
	for (int i = 0; i < TOTAL_TEST_CASES; ++i) {
		ts1->add(BOOST_TEST_CASE(testFunction));
	}

	boost::unit_test::framework::master_test_suite().add(ts1);

	return true;
}

int main(int argc, char* argv[])
{
	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
