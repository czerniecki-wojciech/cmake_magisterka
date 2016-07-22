
#include "gtest/gtest.h"

void Foo(int number) {
	ASSERT_TRUE(number != 3);
}

TEST(SubroutineAsserts, Test) {
	EXPECT_NO_FATAL_FAILURE(Foo(3));
	ASSERT_NO_FATAL_FAILURE(Foo(3));
	ASSERT_TRUE(false);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
