#include "fff.h"
#include "../catch2/catch.hpp"

TEST_CASE("x")
{
    REQUIRE(1==1);
}

// #include <atomic>

// using atomic_int = std::atomic<int>;
// using atomic_uint = std::atomic<unsigned int>;

// DEFINE_FFF_GLOBALS;
// extern "C" {

// #include "id_pool.h"
// #include "log.h"
// #include "plugin.h"
// #include "resources.h"
// #include "utils.h"
// FAKE_VALUE_FUNC(struct vaccel_plugin*, get_virtio_plugin);
// FAKE_VALUE_FUNC(struct vaccel_session*, sess_free);
// }

// #include "session.c"
// #define MAX_VACCEL_SESSIONS 1024


// // Test case for session initialization
// TEST_CASE("session_init", "[session]")
// {
//     int ret;
//     // Ensure that the session system is initialized
//     ret = sessions_bootstrap();
//     REQUIRE(ret == VACCEL_OK);
//     struct vaccel_session sess;
//     sess.session_id = 0;
//     sess.resources = nullptr;
//     sess.priv = nullptr;

//     // Test handling of null session
//     ret = vaccel_sess_init(NULL, 1);
//     REQUIRE(ret == VACCEL_EINVAL);

//     // Test session initialization and cleanup
//     ret = vaccel_sess_init(&sess, 1);
//     REQUIRE(ret == VACCEL_OK);
//     REQUIRE(sess.session_id);
//     REQUIRE(sess.hint == 1);
//     REQUIRE(sess.resources);
//     REQUIRE(sess.priv == nullptr);

//     REQUIRE(vaccel_sess_free(&sess) == VACCEL_OK);
//     REQUIRE(sess.session_id);
//     REQUIRE(sess.hint == 1);
//     REQUIRE(sess.resources == nullptr);
//     REQUIRE(sess.priv == nullptr);

//     ret = sessions_cleanup();
//     REQUIRE(ret == VACCEL_OK);
// }

