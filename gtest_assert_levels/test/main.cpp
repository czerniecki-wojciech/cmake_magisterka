
#include "gtest/gtest.h"

//struktura wyjatku
struct my_exception
{
	explicit my_exception(int ec = 0) : my_error_code(ec) {}

	int my_error_code;
};

//funkcja dzielaca liczbe a przez liczbe podana jako parametr
int divideThreeBy(int a) {
	if (a == 0) // wyjatek rzucany w momencie kiedy podany argument rowny jest 0
		throw my_exception(-1);
	return 3 / a;
}

//definicja testu
TEST(TestCase1, Fatal) {
	//sprawdzenie rownosci
	ASSERT_EQ(1, 1);
	//sprawdzenie czy 1 jest rozne od 2
	ASSERT_NE(1, 2);
	//sprawdzenie czy 1 < 2
	ASSERT_LT(1, 2);
	//sprawdzenie czy 1 <= 2
	ASSERT_LE(2, 2);
	//sprawdzenie czy 3 > 2
	ASSERT_GT(3, 2);
	//sprawdzenie czy 3 >= 2
	ASSERT_GE(3, 3);
	//sprawdzenie czy warunkek logiczny jest prawda
	ASSERT_TRUE(1 == 1);
	//sprawdzenie czy warunkek logiczny jest falszem
	ASSERT_FALSE(1 == 2);
	//prownanie dwoch ciagow znakow
	ASSERT_STREQ("string1", "string1");
	//prownanie czy dwa ciagi znakow sa rozna
	ASSERT_STRNE("string1", "1");
	//prownanie dwoch ciagow znakow nie uwzgledniajac wielkosci liter
	ASSERT_STRCASEEQ("string1", "String1");
	//prownanie czy dwa ciagi znakow sa rozna nie uwzgledniajac wielkosci liter
	ASSERT_STRCASENE("string1", "String2");
	//sprawdzenie czy kod rzuca okreslony wyjatek
	ASSERT_THROW(divideThreeBy(0), my_exception);
	//sprawdzenie czy kod rzuca jakikolwiej wyjatek
	ASSERT_ANY_THROW(divideThreeBy(0));
	//sprawdzenie czy kod nie rzuca wyjatku
	ASSERT_NO_THROW(divideThreeBy(3));
	//porownywanie liczb zmiennoprzecinkowych
	ASSERT_FLOAT_EQ(100.0f, 100.00001f);
	ASSERT_DOUBLE_EQ(100.0, 100.00000000000001);
	//porownywanie liczb zmiennoprzecinkowych z uwzglednieniem bledu
	ASSERT_NEAR(1.0, 9.0, 10.0);
	//wymuszenie bledu
	//FAIL();
	//informacja o sukcesie
	SUCCEED();
}

TEST(AssertLevelTest, NonFatal) {
	//sprawdzenie rownosci
	EXPECT_EQ(1, 1);
	//sprawdzenie czy 1 jest rozne od 2
	EXPECT_NE(1, 2);
	//sprawdzenie czy 1 < 2
	EXPECT_LT(1, 2);
	//sprawdzenie czy 1 <= 2
	EXPECT_LE(2, 2);
	//sprawdzenie czy 3 > 2
	EXPECT_GT(3, 2);
	//sprawdzenie czy 3 >= 2
	EXPECT_GE(3, 3);
	//sprawdzenie czy warunkek logiczny jest prawda
	EXPECT_TRUE(1 == 1);
	//sprawdzenie czy warunkek logiczny jest falszem
	EXPECT_FALSE(1 == 2);
	//prownanie dwoch ciagow znakow
	EXPECT_STREQ("string1", "string1");
	//prownanie czy dwa ciagi znakow sa rozna
	EXPECT_STRNE("string1", "1");
	//prownanie dwoch ciagow znakow nie uwzgledniajac wielkosci liter
	EXPECT_STRCASEEQ("string1", "String1");
	//prownanie czy dwa ciagi znakow sa rozna nie uwzgledniajac wielkosci liter
	EXPECT_STRCASENE("string1", "String2");
	//sprawdzenie czy kod rzuca okreslony wyjatek
	EXPECT_THROW(divideThreeBy(0), my_exception);
	//sprawdzenie czy kod rzuca jakikolwiej wyjatek
	EXPECT_ANY_THROW(divideThreeBy(0));
	//sprawdzenie czy kod nie rzuca wyjatku
	EXPECT_NO_THROW(divideThreeBy(3));
	//wymuszenie bledu
	//ADD_FAILURE();
	//ADD_FAILURE_AT(__FILE__, __LINE__);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    RUN_ALL_TESTS();
    return 0;
}
