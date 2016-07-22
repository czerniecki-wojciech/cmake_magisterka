#include "gtest/gtest.h"
#include "../src/simple_calc.h"

//definicja klasy pomocniczej dla testow parametryzowanych
class MyTestWithParam : public ::testing::TestWithParam<int>
{
protected:
	simple_calc sc;
};

//definicja testu parametryzowanego
TEST_P(MyTestWithParam, ParamAddWithZeroShouldBeEqualParam) {
	//cialo testu
	ASSERT_EQ(sc.addInts(GetParam(), 0), GetParam());
}
//przykladowe parametry
std::vector<int> paramVector = { 1, 2, 3, 4, 5 };
//okreslenie testu MyTestWithParam jako testu parametryzowanego na podanych typach
INSTANTIATE_TEST_CASE_P(TestsWithRange, MyTestWithParam, ::testing::Values(1, 2, 3, 4, 5));

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}