
#define BOOST_TEST_DYN_LINK
#include <boost\test\unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include "../src/simple_calc.h"

void free_test_function(int digit)
{
    BOOST_CHECK(digit % 2 == 1);
}

bool init_unit_test_suite()
{
    int params[] = { 1, 3, 5, 7, 9 };

    boost::unit_test::framework::master_test_suite().
        add(BOOST_PARAM_TEST_CASE(&free_test_function, params, params + 5));
    return true;
}

int main(int argc, char* argv[])
{
    return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
