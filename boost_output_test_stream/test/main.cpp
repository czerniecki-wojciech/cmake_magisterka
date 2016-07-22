#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp> 
//naglowek do modulu realizujacego wypisanie podawanej w metodzi printString wartosci do strumienia otrzymywanego jako referencja w parametrze konstruktora
#include "..\src\PrintingComponent.h"

//definicja grupy testow
BOOST_AUTO_TEST_SUITE(OutputStreamTest)

//definicja testu
BOOST_AUTO_TEST_CASE(OutputStreamTest)
{
	//definicja komponentu do testowania strumienia wyjsciowego
	boost::test_tools::output_test_stream testStream;
	//stworzenie komponentu wykorzystujacego przekazany przez referencje strumien testowy
	PrintingComponent pc(testStream);

	const char* const a = "string to be tested";
	//wywolanie zapisanu ciagu a do strumienia
	pc.printString(a);
	//weryfikacja wypisanego ciagu
	BOOST_CHECK(testStream.is_equal(a));
}

//koniec definicji grupy testów
BOOST_AUTO_TEST_SUITE_END()