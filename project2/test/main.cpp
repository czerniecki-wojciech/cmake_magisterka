// example000_google.cpp : Defines the entry point for the console application.
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost\test\unit_test.hpp>

#include "../src/simple_calc.h"

BOOST_AUTO_TEST_CASE(TC1)
{
    simple_calc sc;
    BOOST_CHECK(3 == sc.addInts(1, 2));
}

