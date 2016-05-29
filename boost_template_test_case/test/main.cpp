
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "../src/simple_calc.h"

BOOST_TEST_CASE_TEMPLATE_FUNCTION(template_test_function, T)
{
    BOOST_CHECK(sizeof(T) == 4);
}

bool init_unit_test_suite()
{
    typedef boost::mpl::list<int, unsigned int, float> types;

    boost::unit_test::framework::master_test_suite().
        add(BOOST_TEST_CASE_TEMPLATE(template_test_function, types));
    return true;
}

int main(int argc, char* argv[])
{
    return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
