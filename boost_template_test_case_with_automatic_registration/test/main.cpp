
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<int, unsigned int, float> types;

BOOST_AUTO_TEST_CASE_TEMPLATE(TestOfTypeSize, T, types)
{
	BOOST_CHECK(sizeof(T) == 4);
}
