
#include "gtest/gtest.h"

void FailTest() {
	std::cerr << "Fix test before attemping to next test case!" << std::endl;
}

void Bar() {
	ASSERT_TRUE(false);
}

void Foo(int number) {
	Bar();

	if (::testing::Test::HasFatalFailure())
		return FailTest();

	ASSERT_TRUE(number != 3);
}

TEST(SubroutineAsserts, Test) {
	Foo(3);

	if (HasFatalFailure())
		return FailTest();

	ASSERT_TRUE(false);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
