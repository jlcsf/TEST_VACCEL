#include "ops/vaccel_ops.h"
#include <catch2/catch_test_macros.hpp>
#include <fff.h>
DEFINE_FFF_GLOBALS;

extern "C" {
#include "misc.h"
}

/*
 * The code below performs unit testing to misc.
 *
 * 1) vaccel_get_plugins()
 *
 */

TEST_CASE("vaccel_get_plugins", "[vaccel_get_plugins]")
{

    struct vaccel_session session;

    SECTION("return correct implementation")
    {

        int result = vaccel_get_plugins(&session, VACCEL_NO_OP);
        REQUIRE(result == VACCEL_OK);

        result = vaccel_get_plugins(&session, VACCEL_EXEC);
        REQUIRE(result == VACCEL_OK);

        result = vaccel_get_plugins(&session, VACCEL_BLAS_SGEMM);
        REQUIRE(result == VACCEL_OK);
    }
}