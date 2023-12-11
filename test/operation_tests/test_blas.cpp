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

<<<<<<< Updated upstream:test/test_blas.cpp
}
=======
TEST_CASE("sgemm", "[blas]")
{

    // Open a file stream for output data
    // FILE* data_fp = NULL;

    // const char* path_output = "../../test/empty.txt";
    // data_fp = fopen(path_output, "wb");
    // REQUIRE(data_fp);

    // Initialize matrices A, B, and C with specific values
    float alpha = 32412.0, beta = 2123.0;
    float A[M * K];
    float B[K * N];
    float C[M * N];
    init(M, N, K, A, B, C);

    // Initialize a VAccel session
    struct vaccel_session session;
    int ret = vaccel_sess_init(&session, 0);
    REQUIRE(ret == VACCEL_OK);

    // Invoke the sgemm function with the initialized matrices and session
    ret = vaccel_sgemm(&session, M, N, K, alpha, (float*)A, K, (float*)B, N,
        beta, (float*)C, N);
    REQUIRE(ret == VACCEL_OK);

    // Write the result matrix C to a file (currently commented out)
    // fwrite(C, sizeof(float), M * N, data_fp);

    // Free the VAccel session
    ret = vaccel_sess_free(&session);
    REQUIRE(ret == VACCEL_OK);
}
>>>>>>> Stashed changes:test/operation_tests/test_blas.cpp
