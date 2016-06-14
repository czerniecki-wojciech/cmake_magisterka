
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp> 

#include <vector>
#include <algorithm>

#include "..\src\PrintingComponent.h"

BOOST_AUTO_TEST_SUITE(OutputStreamTest)

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
	if (v1.size() != v2.size()) {
		boost::test_tools::predicate_result res(false);

		res.message() << "Vectors have different size: " << v1.size() << " != " << v2.size();

		return res;
	}

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

BOOST_AUTO_TEST_CASE(OutputStreamTest)
{
	
	std::vector<int> v1{ 1, 2, 3, 4 };
	std::vector<int> v2{ 2, 2, 3, 4 };
	std::vector<int> v3{ 1, 2, 3};

	BOOST_CHECK(compareVectors(v1, v1));
	BOOST_CHECK(compareVectors(v1, v2));
	BOOST_CHECK(compareVectors(v1, v3));
}

BOOST_AUTO_TEST_SUITE_END()