#include "gtest/gtest.h"
//klasa pomocnicza dla test�w szablonowych
template <typename T>
class MyTypeTestFixture : public ::testing::Test
{
public:
};
//definicja typ�w szablon�w
using MyTestTypes = ::testing::Types<char, int, unsigned int>;
//zdefiniowanie typ�w dla testow
TYPED_TEST_CASE(MyTypeTestFixture, MyTestTypes);
//definicja testu szablonowego
TYPED_TEST(MyTypeTestFixture, TestOfTypeSize)
{
	//cialo testu
	ASSERT_EQ(sizeof(TypeParam), 4);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}