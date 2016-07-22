#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <vector>

//zdefiniowanie intVector jako wektor liczb calkowitych
typedef std::vector<int> intVector;
//wylacznie wypisywania danych o zmiennych typu intVector
BOOST_TEST_DONT_PRINT_LOG_VALUE(intVector);

//definicja grupy testow
BOOST_AUTO_TEST_SUITE(testSuite1)

//definicja testu
BOOST_AUTO_TEST_CASE(test_case1)
{
	//cialo testu
	//przykladowe dane
	intVector iv1 = { 1, 2 };
	intVector iv2 = { 4, 3 };
	//porwianie dwoch zmiennych typu intVector
	BOOST_CHECK_EQUAL(iv1, iv2);
}

//koniec definicji grupy testów
BOOST_AUTO_TEST_SUITE_END()
