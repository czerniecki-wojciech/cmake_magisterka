
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

void test_case1() {
	BOOST_CHECK(1 == 1);
}


void test_case2() {
	BOOST_CHECK(1 == 1);
}


void test_case3() {
	BOOST_CHECK(1 == 1);
}

bool init_unit_test_suite()
{
	boost::unit_test::test_suite* ts1 = BOOST_TEST_SUITE("Test Suite 1");
	ts1->add(BOOST_TEST_CASE(test_case1));
	ts1->add(BOOST_TEST_CASE(test_case2));

	boost::unit_test::test_suite* ts2 = BOOST_TEST_SUITE("Test Suite 2");
	ts2->add(BOOST_TEST_CASE(test_case3));

	boost::unit_test::framework::master_test_suite().add(ts1);
	boost::unit_test::framework::master_test_suite().add(ts2);

	boost::unit_test::framework::master_test_suite().p_name.value = "master test suite name";

	return true;
}

int main(int argc, char* argv[])
{
	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
