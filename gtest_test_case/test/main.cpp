
#include "gtest/gtest.h"

TEST(TestCase1, Fatal) {
	ASSERT_TRUE(true);
}

TEST(TestCase2, Fatal) {
	ASSERT_TRUE(true);
}

TEST(TestCase1, Fatal1) {
	ASSERT_TRUE(true);
}

TEST(TestCase2, Fatal1) {
	ASSERT_TRUE(true);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}
