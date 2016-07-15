
#include "gtest/gtest.h"

#include "../src/simple_calc.h"

class MyTestWithParam : public ::testing::TestWithParam<int>
{
protected:
	simple_calc sc;
	int addIntsWrapper(int a) {
		return sc.addInts(GetParam(), a);
	}
};

TEST_P(MyTestWithParam, ParamAddWithZeroShouldBeEqualParam) {
	ASSERT_EQ(sc.addInts(GetParam(), 0), GetParam());
}

std::vector<int> paramVector = { 1, 2, 3, 4, 5 };

//only one is suitable here, otherwise there is a symbol redefinition
//INSTANTIATE_TEST_CASE_P(TestsWithRange, MyTestWithParam, ::testing::ValuesIn(paramVector.begin(), paramVector.end()));
INSTANTIATE_TEST_CASE_P(TestsWithRange, MyTestWithParam, ::testing::Values(1, 2, 3, 4, 5));

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}
