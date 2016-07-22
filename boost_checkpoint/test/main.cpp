#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

//definicja grupy testow
BOOST_AUTO_TEST_SUITE(testSuite1)

int div(int a)
{
	return 30 / (3 - a);
}
//definicja testu
BOOST_AUTO_TEST_CASE(test_case1)
{
	for (int i = 0; i < 5; ++i)
	{
		//ustawienie punktu kontrolnego posiadajacego informacje na temat ostatniej wartosci i w przebiegu petli
		BOOST_TEST_CHECKPOINT("Checkpoint for i = " << i);
		div(i);
	}
}
//koniec definicji grupy testow
BOOST_AUTO_TEST_SUITE_END()
