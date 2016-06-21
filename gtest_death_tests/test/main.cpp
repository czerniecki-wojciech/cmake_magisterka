
#include "gtest/gtest.h"

int divide100By(int& div) {
	if (div == 0) {
		std::cerr << "Can not divide by 0";
		exit(-1);
	}
	return 100 / div;
}

TEST(DeathTest, Test) {
	EXPECT_DEATH({
		int div = 0;
	    int a = divide100By(div);
	}, "Can not divide by 0");
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
