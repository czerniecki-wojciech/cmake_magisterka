#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

//definicja grupy testow
BOOST_AUTO_TEST_SUITE(testSuite1)

//zdefiniowanie maksymalnej liczny niepowodzen w tescie
BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_case1, 1);

//definicja testu
BOOST_AUTO_TEST_CASE(test_case1)
{
	BOOST_CHECK(true == false);
	BOOST_CHECK(2 == 2);
}
//koniec definicji grupy testow
BOOST_AUTO_TEST_SUITE_END()
