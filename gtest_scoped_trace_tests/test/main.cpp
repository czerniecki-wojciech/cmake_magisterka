
#include "gtest/gtest.h"

#include <sstream>

TEST(ScopedTraces, Test) {
	for (int i = 0; i < 10; ++i) {
		std::ostringstream oss;
		oss << "Test failed for i=" << i << std::endl;

		SCOPED_TRACE(oss.str());
		EXPECT_TRUE(i < 5);
	}
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
