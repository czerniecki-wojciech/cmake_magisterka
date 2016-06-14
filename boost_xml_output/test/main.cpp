
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>

struct MyFixture
{
	MyFixture()
	{
		boost::unit_test::unit_test_log.set_format(boost::unit_test::OF_XML);
	}
	~MyFixture() {}
};

BOOST_GLOBAL_FIXTURE(MyFixture);

BOOST_AUTO_TEST_SUITE(testSuite1)

BOOST_AUTO_TEST_CASE(test_case1)
{
	BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()
