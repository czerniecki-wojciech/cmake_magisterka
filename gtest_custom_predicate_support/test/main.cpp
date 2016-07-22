#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

//funkcja pomocnicza to wypisywania zawartosci wektora
template <typename T>
void printVectorToPredicateResult(const std::vector<T>& v, ::testing::AssertionResult& ar)
{
	if (v.size() > 0)
	{
		ar << v.at(0);

		if (v.size() > 1)
		{
			std::for_each(v.begin() + 1, v.end(), [&ar](auto el) {
				ar << ", " << el;
			});
		}
	}
}

template <typename T>
::testing::AssertionResult compareVectors(const std::vector<T>& v1, const std::vector<T>& v2)
{
	if (v1.size() != v2.size()) { //sprawdzenie dlugosci wektorow
		::testing::AssertionResult res = ::testing::AssertionFailure(); //definicja obiektu przechowujacego komunikat o powodzie uznania testu za zakonczony niepowodzeniem
		res << "Vectors have different size: " << v1.size() << " != " << v2.size();

		return res;
	}
	//sprawdzenie czy zawartosc wektorow jest taka sama
	if (!std::equal(v1.begin(), v1.end(), v2.begin(), v2.end()))
	{
		::testing::AssertionResult res = ::testing::AssertionFailure();

		res << "Different vectors:\nv1 = [";
		printVectorToPredicateResult(v1, res);
		res << "]\n\nv2 = [";
		printVectorToPredicateResult(v2, res);
		res << "]";

		return res;
	}

	return ::testing::AssertionSuccess();
}


template <typename T>
::testing::AssertionResult compareVectors(const char* m_arg, const char* n_arg, const std::vector<T>& v1, const std::vector<T>& v2)
{
	return compareVectors(v1, v2) << " First arg name: " << m_arg << ". Second arg name: " << n_arg;
}
//definicja testu
TEST(TestCase1, VectorTest) {
	//przykladowe dane
	std::vector<int> v1{ 1, 2, 3, 4 };
	std::vector<int> v2{ 2, 2, 3, 4 };
	std::vector<int> v3{ 1, 2, 3 };

	//porownywanie wektorow
	EXPECT_TRUE(compareVectors(v1, v1));
	EXPECT_TRUE(compareVectors(v1, v2));
	EXPECT_TRUE(compareVectors(v1, v3));

	EXPECT_PRED_FORMAT2(compareVectors, v1, v1);
	EXPECT_PRED_FORMAT2(compareVectors, v1, v2);
	EXPECT_PRED_FORMAT2(compareVectors, v1, v3);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}
