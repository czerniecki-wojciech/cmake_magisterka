
#include "gtest/gtest.h"

#include "../src/simple_calc.h"

template <typename T>
class MyTypeTestFixture : public ::testing::Test
{
public:
};

using MyTestTypes = ::testing::Types<char, int, unsigned int>;

TYPED_TEST_CASE(MyTypeTestFixture, MyTestTypes);

TYPED_TEST(MyTypeTestFixture, TestOfTypeSize)
{
	ASSERT_EQ(sizeof(TypeParam), 4);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
