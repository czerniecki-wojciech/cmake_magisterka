
#include "gtest/gtest.h"

TEST(LoggingAdditionalInformation, Test) {
	RecordProperty("testValue1", 10);
	RecordProperty("testValue2", "20");
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
