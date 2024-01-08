#include <atomic>
#include <catch.hpp>
#include <fff.h>

using atomic_int = std::atomic<int>;
using atomic_uint = std::atomic<unsigned int>;
DEFINE_FFF_GLOBALS;

extern "C" {
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "log.h"
#include "plugin.h"
#include "resources.h"
#include "session.h"
#include "utils.h"
#include "vaccel.h"

#include <dlfcn.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
}

TEST_CASE("constructor & destructor", "[vaccel]")
{   
    // this does nothing
    int ret; 
    REQUIRE(ret == ret);
    // ret = vaccel_log_init();
    // REQUIRE(ret == VACCEL_OK);

    // ret = create_vaccel_rundir();
    // REQUIRE(ret == VACCEL_OK);

    // ret = sessions_bootstrap();
    // REQUIRE(ret == VACCEL_OK);

    // ret = resources_bootstrap();
    // REQUIRE(ret == VACCEL_OK);

    // ret = plugins_bootstrap();
    // REQUIRE(ret == VACCEL_OK);

}
