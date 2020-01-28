#define BOOST_TEST_MODULE test_vers_boost

#include <boost/test/unit_test.hpp>
#include "vers_lib.h"

BOOST_AUTO_TEST_SUITE(test_vers_boost)

BOOST_AUTO_TEST_CASE(test_valid_version) {
    BOOST_CHECK(version_patch() >  0);
    BOOST_CHECK(version_minor() >= 0);
    BOOST_CHECK(version_major() >= 0);
}

} // BOOST_AUTO_TEST_SUITE ends
