#include "gtest/gtest.h"

//funkcja powodujaca zakonczie programu
int divide100By(int div) {
	if (div == 0) {
		std::cerr << "Can not divide by 0";
		exit(-1);
	}
	return 100 / div;
}

TEST(DeathTests, Test) {
	//sprawdzenie czy uruchomiony program zakonczyl sie oraz czy na strumieniu cerr znalazla sie okreslona wiadomosc
	EXPECT_DEATH(divide100By(0), "Can not divide by 0");
	ASSERT_DEATH(divide100By(0), "Can not divide by 0");
	//jak powyzej lecz ze sprawdzeniem czy dana funkcjonalnosc dziala
	EXPECT_DEATH_IF_SUPPORTED(divide100By(0), "Can not divide by 0");
	ASSERT_DEATH_IF_SUPPORTED(divide100By(0), "Can not divide by 0");
	//jak powyzej lecz z dodatkowym sprawdzeniem kodu bledu
	EXPECT_EXIT(divide100By(0), ::testing::ExitedWithCode(-1), "Can not divide by 0");
	ASSERT_EXIT(divide100By(0), ::testing::ExitedWithCode(-1), ".*");
	//powyzej mozliwosc zastosowania wyrazen regularnych do sprawdzenia danych ze strumienia cerr
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();
    return 0;
}