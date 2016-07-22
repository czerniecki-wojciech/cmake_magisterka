#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp> //wymagane do porownan liczb w standardzie IEEE754

//struktura wyjatku
struct my_exception
{
	explicit my_exception(int ec = 0) : my_error_code(ec) {}

	int my_error_code; //kod wyjatku
};

//funkcja dzielaca liczbe a przez liczbe podana jako parametr
int divideThreeBy(int a) {
	if (a == 0) // wyjatek rzucany w momencie kiedy podany argument rowny jest 0
		throw my_exception(-1);
	return 3 / a;
}
//definicja grupy testow
BOOST_AUTO_TEST_SUITE(DifferentCheckLevels)
//definicja testu
BOOST_AUTO_TEST_CASE(TestsWithWarnLevel)
{
	//przykladowe dane
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	//sprawdzenie wyrazenia logicznego
	BOOST_WARN(true);
	//sprawdzenie rownosci
	BOOST_WARN_EQUAL(1, 1);
	//porownanie danych bitowo
	BOOST_WARN_BITWISE_EQUAL(0x001, 0x001);
	//przyklad porowania liczb, bez zastosowania specjalnego operatora, wynik jest przeklamany
	BOOST_WARN_EQUAL(1.000000000f, 1.0000000001f);
	//porownywanie liczb zmiennoprzecinkowych z uwzglednieniem bledu
	BOOST_WARN_CLOSE(100.0f, 101.0f, 10.0f);
	BOOST_WARN_CLOSE_FRACTION(100.0f, 101.0f, 10.0f);
	//porownywanie kolekcji danych
	BOOST_WARN_EQUAL_COLLECTIONS(intAttay1, intAttay1 + sizeOfIntArray1, intAttay2, intAttay2 + sizeOfIntArray2);
	//weryfikacja kodu oraz typu rzucanego wyjatku
	BOOST_WARN_EXCEPTION(throw my_exception(1), my_exception, [](auto a)->bool {return a.my_error_code == 1; });
	//porowanie czy 2 >= 1
	BOOST_WARN_GE(2, 1);
	//porowanie czy 2 > 1
	BOOST_WARN_GT(2, 1);
	//porowanie czy 0 <= 1
	BOOST_WARN_LE(0, 1);
	//porowanie czy 0 < 1
	BOOST_WARN_LT(0, 1);
	//sprawdzenie warunku logicznego wraz z dodatkowa informacja w razie niepowodzenia
	BOOST_WARN_MESSAGE(1 == 1, "1 is not equal 1?!");
	//sprawdzenie czy 1 jest rozne od 2
	BOOST_WARN_NE(1, 2);
	//sprawdzenie czy kod nie rzuca wyjatku
	BOOST_WARN_NO_THROW(divideThreeBy(3));
	//sprawdzenie czy kod rzuca okreslony wyjatek
	BOOST_WARN_THROW(divideThreeBy(0), my_exception);
	//sprawdzenie z uzyciem predykatu
	BOOST_WARN_PREDICATE([](int a, int b)->bool {return a == b; }, (1)(1));
}

BOOST_AUTO_TEST_CASE(TestsWithCheckLevel)
{
	//przykladowe dane
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	//sprawdzenie wyrazenia logicznego
	BOOST_CHECK(true);
	//sprawdzenie rownosci
	BOOST_CHECK_EQUAL(1, 1);
	//porownanie danych bitowo
	BOOST_CHECK_BITWISE_EQUAL(0x001, 0x001);
	//przyklad porowania liczb, bez zastosowania specjalnego operatora, wynik jest przeklamany
	BOOST_CHECK_EQUAL(1.000000000f, 1.0000000001f);
	//porownywanie liczb zmiennoprzecinkowych z uwzglednieniem bledu
	BOOST_CHECK_CLOSE(100.0f, 101.0f, 10.0f);
	BOOST_CHECK_CLOSE_FRACTION(100.0f, 101.0f, 10.0f);
	//porownywanie kolekcji danych
	BOOST_CHECK_EQUAL_COLLECTIONS(intAttay1, intAttay1 + sizeOfIntArray1, intAttay2, intAttay2 + sizeOfIntArray2);
	//weryfikacja kodu oraz typu rzucanego wyjatku
	BOOST_CHECK_EXCEPTION(throw my_exception(1), my_exception, [](auto a)->bool {return a.my_error_code == 1; });
	//porowanie czy 2 >= 1
	BOOST_CHECK_GE(2, 1);
	//porowanie czy 2 > 1
	BOOST_CHECK_GT(2, 1);
	//porowanie czy 0 <= 1
	BOOST_CHECK_LE(0, 1);
	//porowanie czy 0 < 1
	BOOST_CHECK_LT(0, 1);
	//sprawdzenie warunku logicznego wraz z dodatkowa informacja w razie niepowodzenia
	BOOST_CHECK_MESSAGE(1 == 1, "1 is not equal 1?!");
	//sprawdzenie czy 1 jest rozne od 2
	BOOST_CHECK_NE(1, 2);
	//sprawdzenie czy kod nie rzuca wyjatku
	BOOST_CHECK_NO_THROW(divideThreeBy(3));
	//sprawdzenie czy kod rzuca okreslony wyjatek
	BOOST_CHECK_THROW(divideThreeBy(0), my_exception);
	//sprawdzenie z uzyciem predykatu
	BOOST_CHECK_PREDICATE([](int a, int b)->bool {return a == b; }, (1)(1));
}

BOOST_AUTO_TEST_CASE(TestsWithRequireLevel)
{
	//przykladowe dane
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	//sprawdzenie wyrazenia logicznego
	BOOST_REQUIRE(true);
	//sprawdzenie rownosci
	BOOST_REQUIRE_EQUAL(1, 1);
	//porownanie danych bitowo
	BOOST_REQUIRE_BITWISE_EQUAL(0x001, 0x001);
	//przyklad porowania liczb, bez zastosowania specjalnego operatora, wynik jest przeklamany
	BOOST_REQUIRE_EQUAL(1.000000000f, 1.0000000001f);
	BOOST_REQUIRE_CLOSE(100.0f, 101.0f, 10.0f);
	//porownywanie liczb zmiennoprzecinkowych z uwzglednieniem bledu
	BOOST_REQUIRE_CLOSE_FRACTION(100.0f, 101.0f, 10.0f);
	//porownywanie kolekcji danych
	BOOST_REQUIRE_EQUAL_COLLECTIONS(intAttay1, intAttay1 + sizeOfIntArray1, intAttay2, intAttay2 + sizeOfIntArray2);
	//weryfikacja kodu oraz typu rzucanego wyjatku
	BOOST_REQUIRE_EXCEPTION(throw my_exception(1), my_exception, [](auto a)->bool {return a.my_error_code == 1; });
	//porowanie czy 2 >= 1
	BOOST_REQUIRE_GE(2, 1);
	//porowanie czy 2 > 1
	BOOST_REQUIRE_GT(2, 1);
	//porowanie czy 0 <= 1
	BOOST_REQUIRE_LE(0, 1);
	//porowanie czy 0 < 1
	BOOST_REQUIRE_LT(0, 1);
	//sprawdzenie warunku logicznego wraz z dodatkowa informacja w razie niepowodzenia
	BOOST_REQUIRE_MESSAGE(1 == 1, "1 is not equal 1?!");
	//sprawdzenie czy 1 jest rozne od 2
	BOOST_REQUIRE_NE(1, 2);
	//sprawdzenie czy kod nie rzuca wyjatku
	BOOST_REQUIRE_NO_THROW(divideThreeBy(3));
	//sprawdzenie czy kod rzuca okreslony wyjatek
	BOOST_REQUIRE_THROW(divideThreeBy(0), my_exception);
	//sprawdzenie z uzyciem predykatu
	BOOST_REQUIRE_PREDICATE([](int a, int b)->bool {return a == b; }, (1)(1));
}

//koniec definicji grupy testow
BOOST_AUTO_TEST_SUITE_END()
