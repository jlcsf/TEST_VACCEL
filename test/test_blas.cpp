#include <catch2/catch_test_macros.hpp>

#include <atomic>

using atomic_int = std::atomic<int>;
using atomic_uint = std::atomic<unsigned int>;

extern "C"
{
#include <vaccel.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#include "session.h"
#include "blas.h"
}



TEST_CASE("sgemm", "[blas]"){

    REQUIRE(1==1);

}