#include "gtest/gtest.h"
//klasa pomocnicza dla test�w szablonowych
template <typename T>
class MyTypeTestFixture : public ::testing::Test
{
public:
};
//zdefiniowanie, ze MyTypeTestFixture bedzie grupa testow szablonowych
TYPED_TEST_CASE_P(MyTypeTestFixture);
//definicja testu szablomowego
TYPED_TEST_P(MyTypeTestFixture, TestOfTypeSize)
{
	//cialo testu
	ASSERT_EQ(sizeof(TypeParam), 4);
}
//rejestracja testu
REGISTER_TYPED_TEST_CASE_P(MyTypeTestFixture, TestOfTypeSize);
//definicja typ�w szablon�w
using MyTestTypes = ::testing::Types<char, int, unsigned int>;
//zdefiniowanie typ�w dla testow
INSTANTIATE_TYPED_TEST_CASE_P(MyTests, MyTypeTestFixture, MyTestTypes);

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}