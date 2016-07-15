
#include "gtest/gtest.h"

#include "../src/simple_calc.h"

template <typename T>
class MyTypeTestFixture : public ::testing::Test
{
public:
};

TYPED_TEST_CASE_P(MyTypeTestFixture);

TYPED_TEST_P(MyTypeTestFixture, TestOfTypeSize)
{
	ASSERT_EQ(sizeof(TypeParam), 4);
}

REGISTER_TYPED_TEST_CASE_P(MyTypeTestFixture, TestOfTypeSize);

using MyTestTypes = ::testing::Types<char, int, unsigned int>;
INSTANTIATE_TYPED_TEST_CASE_P(MyTests, MyTypeTestFixture, MyTestTypes);

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
