#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>

//definicja grupy testow
BOOST_AUTO_TEST_SUITE(OutputStreamTest)

//funkcja pomocnicza to wypisywania zawartosci wektora
template <typename T>
void printVectorToPredicateResult(std::vector<T>& v, boost::test_tools::predicate_result& pr)
{
	if (v.size() > 0)
	{
		pr.message() << v.at(0);

		if (v.size() > 1)
		{
			std::for_each(v.begin() + 1, v.end(), [&pr](auto el) {
				pr.message() << ", " << el;
			});
		}
	}
}

template <typename T>
boost::test_tools::predicate_result compareVectors(std::vector<T>& v1, std::vector<T>& v2)
{
	if (v1.size() != v2.size()) { //sprawdzenie dlugosci wektorów
		boost::test_tools::predicate_result res(false); //definicja obiektu przechowujacego komunikat o powodzie uznania testu za zakonczony niepowodzeniem

		res.message() << "Vectors have different size: " << v1.size() << " != " << v2.size();

		return res;
	}
	//sprawdzenie czy zawartosc wektorow jest taka sama
	if (!std::equal(v1.begin(), v1.end(), v2.begin(), v2.end()))
	{
		boost::test_tools::predicate_result res(false);

		res.message() << "Different vectors:\nv1 = [";
		printVectorToPredicateResult(v1, res);
		res.message() << "]\n\nv2 = [";
		printVectorToPredicateResult(v2, res);
		res.message() << "]";

		return res;
	}

	return true;
}

//definicja testu
BOOST_AUTO_TEST_CASE(OutputStreamTest)
{
	//przykladowe dane
	std::vector<int> v1{ 1, 2, 3, 4 };
	std::vector<int> v2{ 2, 2, 3, 4 };
	std::vector<int> v3{ 1, 2, 3};
	//porownywanie wektorow
	BOOST_CHECK(compareVectors(v1, v1));
	BOOST_CHECK(compareVectors(v1, v2));
	BOOST_CHECK(compareVectors(v1, v3));
}

//koniec definicji grupy testów
BOOST_AUTO_TEST_SUITE_END()