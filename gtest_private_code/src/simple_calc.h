#pragma once

#include <gtest\gtest_prod.h>

class simple_calc
{
	FRIEND_TEST(SimpleCalcTest, PrivateMemberTest);
private:
	int lastSum;
	int getLastSum();
	bool initialized;
public:
	void init();
	int addInts(int a, int b);
	simple_calc();
	~simple_calc();
};

