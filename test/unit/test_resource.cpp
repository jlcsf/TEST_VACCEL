#include <atomic>
#include "../catch2/catch.hpp"

using atomic_int = std::atomic<int>;
using atomic_uint = std::atomic<unsigned int>;

extern "C" {
#include "error.h"
#include "id_pool.h"
#include "list.h"
#include "log.h"
#include "plugin.h"
#include "resources.h"
#include "utils.h"
#include "vaccel.h"
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Mock cleanup function for resources
int cleanup_resource_mock([[maybe_unused]] void* data) { return 0; }

/*
 *
 * The code below performs unit testing to resources.
 *
 * 1) resource_bootsrap()
 * 2) resource_new()
 * 3) resource_destory()
 * 4) resource_create_rundir()
 * 5) resource_get_by_id()
 *
 */

// Test case for resource destruction
TEST_CASE("destroy_OK", "[Resources]")
{
    int ret;
    struct vaccel_resource res;
    vaccel_resource_t test_type = VACCEL_RES_TF_MODEL;
    void* test_data = nullptr;
    int (*cleanup_res_test)(void*) = cleanup_resource_mock;

    // Ensure that the resource system is initialized
    ret = resources_bootstrap();
    REQUIRE(ret == VACCEL_OK);

    // Test handling of null resource
    SECTION("Null resource")
    {
        ret = resource_new(NULL, test_type, test_data, cleanup_res_test);
        REQUIRE(ret == VACCEL_EINVAL);
    }

    // Test creation and destruction of a valid resource
    SECTION("Valid resource")
    {
        ret = resource_new(&res, test_type, test_data, cleanup_res_test);
        REQUIRE(ret == VACCEL_OK);

        REQUIRE(res.id == 1);
        REQUIRE(res.type == VACCEL_RES_TF_MODEL);
        REQUIRE(res.data == nullptr);
        REQUIRE_FALSE(list_empty(&res.entry));
        REQUIRE(res.refcount == 0);
        REQUIRE(res.rundir == NULL);

        ret = resource_destroy(&res);

        REQUIRE(res.id == 1);
        REQUIRE(res.type == VACCEL_RES_TF_MODEL);
        REQUIRE(res.data == nullptr);
        REQUIRE(list_empty(&res.entry));
        REQUIRE(res.refcount == 0);
        REQUIRE(res.rundir == NULL);

        REQUIRE(ret == VACCEL_OK);
    }

    REQUIRE(resources_cleanup() == VACCEL_OK);
}

// Test case for resource creation and rundir creation
TEST_CASE("Resource Create Rundir", "[Resources]")
{

    int ret;
    struct vaccel_resource res;
    vaccel_resource_t test_type = VACCEL_RES_TF_MODEL;
    void* test_data = nullptr;
    int (*cleanup_res_test)(void*) = cleanup_resource_mock;

    // Ensure that the resource system is initialized
    ret = resources_bootstrap();
    REQUIRE(ret == VACCEL_OK);

    // Create a resource
    ret = resource_new(&res, test_type, test_data, cleanup_res_test);
    REQUIRE(ret == VACCEL_OK);

    REQUIRE(res.id == 1);
    REQUIRE(res.type == VACCEL_RES_TF_MODEL);
    REQUIRE(res.data == nullptr);
    REQUIRE_FALSE(list_empty(&res.entry));
    REQUIRE(res.refcount == 0);
    REQUIRE(res.rundir == NULL);

    // Test rundir creation
    ret = resource_create_rundir(&res);
    REQUIRE(ret == VACCEL_OK);

    REQUIRE(res.id == 1);
    REQUIRE(res.type == VACCEL_RES_TF_MODEL);
    REQUIRE(res.data == nullptr);
    REQUIRE_FALSE(list_empty(&res.entry));
    REQUIRE(res.refcount == 0);
    REQUIRE_FALSE(res.rundir == NULL);

    // Cleanup the resource
    ret = resource_destroy(&res);
    REQUIRE(ret == VACCEL_OK);

    REQUIRE(res.id == 1);
    REQUIRE(res.type == VACCEL_RES_TF_MODEL);
    REQUIRE(res.data == nullptr);
    REQUIRE(list_empty(&res.entry));
    REQUIRE(res.refcount == 0);
    REQUIRE_FALSE(res.rundir == NULL);

    REQUIRE(resources_cleanup() == VACCEL_OK);
}

// Test case for finding a resource by ID (failure case)
TEST_CASE("find_resource_by_id_fail", "[Resources]")
{
    struct vaccel_resource* test_res = nullptr;
    vaccel_id_t test_id = 0;

    // Attempt to find a resource by ID which fails (ID of 0 doesn't exist -
    // starts at 1)
    int ret = resource_get_by_id(&test_res, test_id);
    REQUIRE(ret == VACCEL_EINVAL);
}

// Test case for finding a resource by ID (success case)
TEST_CASE("find_resource_by_id", "[Resources]")
{
    int result;
    struct vaccel_resource test_res;
    vaccel_resource_t test_type = VACCEL_RES_TF_MODEL;
    void* test_data = nullptr;
    int (*cleanup_res_test)(void*) = cleanup_resource_mock;

    // Ensure that the resource system is initialized
    result = resources_bootstrap();
    REQUIRE(result == VACCEL_OK);

    // Create a test resource
    result = resource_new(&test_res, test_type, test_data, cleanup_res_test);
    REQUIRE(result == VACCEL_OK);

    REQUIRE(test_res.id == 1);
    REQUIRE(test_res.type == VACCEL_RES_TF_MODEL);
    REQUIRE(test_res.data == nullptr);
    REQUIRE_FALSE(list_empty(&test_res.entry));
    REQUIRE(test_res.refcount == 0);
    REQUIRE(test_res.rundir == NULL);

    // Attempt to find the resource by ID and ensure success
    struct vaccel_resource* result_resource = nullptr;
    vaccel_id_t id_to_find = 1;

    int ret = resource_get_by_id(&result_resource, id_to_find);
    REQUIRE(ret == VACCEL_OK);
    REQUIRE(result_resource != nullptr);

    REQUIRE(result_resource->id == 1);
    REQUIRE(result_resource->type == VACCEL_RES_TF_MODEL);
    REQUIRE(result_resource->data == nullptr);
    REQUIRE_FALSE(list_empty(&result_resource->entry));
    REQUIRE(result_resource->refcount == 0);
    REQUIRE(result_resource->rundir == NULL);

    // Cleanup the test resource
    result = resource_destroy(&test_res);
    REQUIRE(result == VACCEL_OK);

    // REQUIRE(resources_cleanup() == VACCEL_OK);
}
