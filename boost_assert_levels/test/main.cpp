
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE example

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

struct my_exception
{
	explicit my_exception(int ec = 0) : my_error_code(ec) {}

	int my_error_code;
};

int divideThreeBy(int a) {
	if (a == 0)
		throw my_exception(-1);
	return 3 / a;
}

BOOST_AUTO_TEST_SUITE(DifferentCheckLevels)

BOOST_AUTO_TEST_CASE(TestsWithWarnLevel)
{
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	BOOST_WARN(true);
	BOOST_WARN_EQUAL(1, 1);
	BOOST_WARN_BITWISE_EQUAL(0x001, 0x001);
	BOOST_WARN_CLOSE(100.0f, 101.0f, 10.0f);
	BOOST_WARN_CLOSE_FRACTION(100.0f, 101.0f, 10.0f);
	BOOST_WARN_EQUAL(2, 2);
	BOOST_WARN_EQUAL_COLLECTIONS(intAttay1, intAttay1 + sizeOfIntArray1, intAttay2, intAttay2 + sizeOfIntArray2);
	BOOST_WARN_EXCEPTION(throw my_exception(1), my_exception, [](auto a)->bool {return a.my_error_code == 1; });
	BOOST_WARN_GE(2, 1);
	BOOST_WARN_GT(2, 1);
	BOOST_WARN_LE(0, 1);
	BOOST_WARN_LT(0, 1);
	BOOST_WARN_MESSAGE(1 == 1, "1 is not equal 1?!");
	BOOST_WARN_NE(1, 2);
	BOOST_WARN_NO_THROW(divideThreeBy(3));
	BOOST_WARN_THROW(divideThreeBy(0), my_exception);
	BOOST_WARN_PREDICATE([](int a, int b)->bool {return a == b; }, (1)(1));
}

BOOST_AUTO_TEST_CASE(TestsWithCheckLevel)
{
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	BOOST_CHECK(true);
	BOOST_CHECK_EQUAL(1, 1);
	BOOST_CHECK_BITWISE_EQUAL(0x001, 0x001);
	BOOST_CHECK_CLOSE(100.0f, 101.0f, 10.0f);
	BOOST_CHECK_CLOSE_FRACTION(100.0f, 101.0f, 10.0f);
	BOOST_CHECK_EQUAL(2, 2);
	BOOST_CHECK_EQUAL_COLLECTIONS(intAttay1, intAttay1 + sizeOfIntArray1, intAttay2, intAttay2 + sizeOfIntArray2);
	BOOST_CHECK_EXCEPTION(throw my_exception(1), my_exception, [](auto a)->bool {return a.my_error_code == 1; });
	BOOST_CHECK_GE(2, 1);
	BOOST_CHECK_GT(2, 1);
	BOOST_CHECK_LE(0, 1);
	BOOST_CHECK_LT(0, 1);
	BOOST_CHECK_MESSAGE(1 == 1, "1 is not equal 1?!");
	BOOST_CHECK_NE(1, 2);
	BOOST_CHECK_NO_THROW(divideThreeBy(3));
	BOOST_CHECK_THROW(divideThreeBy(0), my_exception);
	BOOST_CHECK_PREDICATE([](int a, int b)->bool {return a == b; }, (1)(1));
}

BOOST_AUTO_TEST_CASE(TestsWithRequireLevel)
{
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	BOOST_REQUIRE(true);
	BOOST_REQUIRE_EQUAL(1, 1);
	BOOST_REQUIRE_BITWISE_EQUAL(0x001, 0x001);
	BOOST_REQUIRE_CLOSE(100.0f, 101.0f, 10.0f);
	BOOST_REQUIRE_CLOSE_FRACTION(100.0f, 101.0f, 10.0f);
	BOOST_REQUIRE_EQUAL(2, 2);
	BOOST_REQUIRE_EQUAL_COLLECTIONS(intAttay1, intAttay1 + sizeOfIntArray1, intAttay2, intAttay2 + sizeOfIntArray2);
	BOOST_REQUIRE_EXCEPTION(throw my_exception(1), my_exception, [](auto a)->bool {return a.my_error_code == 1; });
	BOOST_REQUIRE_GE(2, 1);
	BOOST_REQUIRE_GT(2, 1);
	BOOST_REQUIRE_LE(0, 1);
	BOOST_REQUIRE_LT(0, 1);
	BOOST_REQUIRE_MESSAGE(1 == 1, "1 is not equal 1?!");
	BOOST_REQUIRE_NE(1, 2);
	BOOST_REQUIRE_NO_THROW(divideThreeBy(3));
	BOOST_REQUIRE_THROW(divideThreeBy(0), my_exception);
	BOOST_REQUIRE_PREDICATE([](int a, int b)->bool {return a == b; }, (1)(1));
}

BOOST_AUTO_TEST_CASE(TestsWithoutLevel)
{
	int intAttay1[] = { 1, 2, 3, 4, 5 };
	int intAttay2[] = { 1, 2, 3, 4, 5 };

	int sizeOfIntArray1 = sizeof(intAttay1) / sizeof(intAttay1[0]);
	int sizeOfIntArray2 = sizeof(intAttay2) / sizeof(intAttay2[0]);

	if (1 == 2) {
		BOOST_ERROR("1 is not equal 2!!!");
		BOOST_FAIL("1 is not equal 2!!!");
	}

	BOOST_CHECK(BOOST_IS_DEFINED(DEF) == false);
}

BOOST_AUTO_TEST_SUITE_END()