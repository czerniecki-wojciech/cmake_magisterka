
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

void test_case1() {
	BOOST_CHECK(true == false);
	BOOST_CHECK(2 == 2);
}

bool init_unit_test_suite()
{
	int expectedFailures = 1;

	boost::unit_test::test_suite* ts1 = BOOST_TEST_SUITE("Test Suite 1");
	ts1->add(BOOST_TEST_CASE(test_case1), expectedFailures);

	boost::unit_test::framework::master_test_suite().add(ts1);

	return true;
}

int main(int argc, char* argv[])
{
	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
