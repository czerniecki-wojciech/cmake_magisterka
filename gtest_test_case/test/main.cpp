#include "gtest/gtest.h"

TEST(TestSuite, TestCase) { /*TestCase - nazwa testu, TestSuite - nazwa grupy test�w*/
	//cialo tstu
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
	return 0;
}