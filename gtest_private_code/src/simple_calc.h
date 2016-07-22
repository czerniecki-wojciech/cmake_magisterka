#pragma once

#include <gtest\gtest_prod.h>

//definicja testowanej klasy
class simple_calc
{
	//zdefiniowanie dostepu dla zmiennych prywatnych dla testu
	FRIEND_TEST(SimpleCalcTest, PrivateMemberTest);
private:
	int lastSum;
	int getLastSum();
	bool initialized;
public:
	void init();
	int addInts(int a, int b);
	simple_calc();
};

