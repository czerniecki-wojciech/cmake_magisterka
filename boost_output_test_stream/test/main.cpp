
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp> 

#include "..\src\PrintingComponent.h"

BOOST_AUTO_TEST_SUITE(OutputStreamTest)

BOOST_AUTO_TEST_CASE(OutputStreamTest)
{
	boost::test_tools::output_test_stream testStream;
	PrintingComponent pc(testStream);

	const char* const a = "string to be tested";

	pc.printString(a);

	BOOST_CHECK(testStream.is_equal(a));
}

BOOST_AUTO_TEST_SUITE_END()