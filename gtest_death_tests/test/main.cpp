
#include "gtest/gtest.h"

int divide100By(int div) {
	if (div == 0) {
		std::cerr << "Can not divide by 0";
		exit(-1);
	}
	return 100 / div;
}

TEST(DeathTests, Test) {
	EXPECT_DEATH(divide100By(0), "Can not divide by 0");

	ASSERT_DEATH(divide100By(0), "Can not divide by 0");

	EXPECT_DEATH_IF_SUPPORTED(divide100By(0), "Can not divide by 0");

	ASSERT_DEATH_IF_SUPPORTED(divide100By(0), "Can not divide by 0");
	
	EXPECT_EXIT(divide100By(0), ::testing::ExitedWithCode(-1), "Can not divide by 0");
	
	ASSERT_EXIT(divide100By(0), ::testing::ExitedWithCode(-1), ".*");
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
