#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

//definicja grupy testow
BOOST_AUTO_TEST_SUITE(testSuite1)

//definicja testu
BOOST_AUTO_TEST_CASE(test_case1)
{
	//wypisanie dodatkowej wiadomosci podczas przetwarzania testu
	BOOST_TEST_MESSAGE("\n***   I'm inside test_case1   ***\n");
}
//koniec definicji grupy testów
BOOST_AUTO_TEST_SUITE_END()