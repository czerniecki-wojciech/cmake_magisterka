
#include "gtest/gtest.h"

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

TEST(TestCase1, Fatal) {
	ASSERT_EQ(1, 1);
	ASSERT_NE(1, 2);
	ASSERT_LT(1, 2);
	ASSERT_LE(2, 2);
	ASSERT_GT(3, 2);
	ASSERT_GE(3, 3);
	ASSERT_TRUE(1 == 1);
	ASSERT_FALSE(1 == 2);
	ASSERT_STREQ("string1", "string1");
	ASSERT_STRNE("string1", "1");
	ASSERT_STRCASEEQ("string1", "String1");
	ASSERT_STRCASENE("string1", "String2");
	ASSERT_THROW(divideThreeBy(0), my_exception);
	ASSERT_ANY_THROW(divideThreeBy(0));
	ASSERT_NO_THROW(divideThreeBy(3));
	ASSERT_FLOAT_EQ(100.0f, 100.00001f);
	ASSERT_DOUBLE_EQ(100.0, 100.00000000000001);
	ASSERT_NEAR(1.0, 9.0, 10.0);
	//FAIL(); //it will fail
}

TEST(AssertLevelTest, NonFatal) {
	EXPECT_EQ(1, 1);
	EXPECT_NE(1, 2);
	EXPECT_LT(1, 2);
	EXPECT_LE(2, 2);
	EXPECT_GT(3, 2);
	EXPECT_GE(3, 3);
	EXPECT_TRUE(1 == 1);
	EXPECT_FALSE(1 == 2);
	EXPECT_STREQ("string1", "string1");
	EXPECT_STRNE("string1", "1");
	EXPECT_STRCASEEQ("string1", "String1");
	EXPECT_STRCASENE("string1", "String2");
	EXPECT_THROW(divideThreeBy(0), my_exception);
	EXPECT_ANY_THROW(divideThreeBy(0));
	EXPECT_NO_THROW(divideThreeBy(3));
	//ADD_FAILURE(); //it will fail
	//ADD_FAILURE_AT(__FILE__, __LINE__); //it will fail
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
