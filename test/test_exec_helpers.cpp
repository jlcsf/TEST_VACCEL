#include <catch2/catch_test_macros.hpp>

#include <atomic>

using atomic_int = std::atomic<int>;
using atomic_uint = std::atomic<unsigned int>;


extern "C"
{
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <vaccel.h>
#include "session.h"
#include "plugin.h"
#include "shared_object.h"

#include "../src/vaccel_args.h"

}

struct mydata
{
	uint32_t size;
	int* array;
};

void* ser(void* buf, uint32_t* bytes){
	struct mydata* non_ser = (struct mydata*)buf;

	uint32_t size = (non_ser->size + 1) * sizeof(int);
	int* ser_buf = (int*)malloc(size);

	memcpy(ser_buf, (int*)(&non_ser->size), sizeof(int));
	
	for(int i=0; i<(int)non_ser->size; i++)
		memcpy(&ser_buf[i+1], &non_ser->array[i], sizeof(int));
	

	*bytes = size;
	return ser_buf;
}


void* deser(void* buf, uint32_t bytes){
    printf("bytes: %d\n", (int)bytes);
	int *ser_buf = (int*)buf;
	int size = ser_buf[0];

	struct mydata* new_buf = 
		(struct mydata*)malloc(sizeof(struct mydata));

	new_buf->size = (uint32_t)size;
	new_buf->array = (int*)malloc(new_buf->size * sizeof(int));
	for(int i=0; i<size; i++)
		memcpy(&new_buf->array[i], &ser_buf[i+1], sizeof(int));

	return new_buf;
}


TEST_CASE("exec_helpers")
{
    int ret;
	struct vaccel_session sess;
    
    sess.hint = VACCEL_PLUGIN_DEBUG;
    char iterations[] = "1";
    
    ret = vaccel_sess_init(&sess, sess.hint);
    REQUIRE(ret == VACCEL_OK);

    struct vaccel_arg_list *read, *write;

    read = vaccel_args_init();
    REQUIRE(read != NULL);
    REQUIRE(read->size == 0);
    REQUIRE(read->list != NULL);
    
    write = vaccel_args_init();
    REQUIRE(write != NULL);
    REQUIRE(write->size == 0);
    REQUIRE(write->list != NULL);
    
    /*
    *
    * 'read' will contain two arguments, one serialised and
    * one non-serialised. The first argument will be an integer,
    * while the second will be an instance of 'struct mydata'.
    * 
    * On the other side, 'write' will also contain two arguments 
    * after calling vaccel_exec(). The arguements will be the same 
    * as before; one integer and one instance of'struct mydata'. 
    *
    */

    int input_int = 10;
    vaccel_add_ser_arg(read, &input_int, sizeof(int));
    REQUIRE(read->size == 1);
    REQUIRE(read->list[0].size == sizeof(int));
    REQUIRE(read->list[0].argtype == 0);
    REQUIRE(read->list[0].buf == &input_int);

    struct mydata input_data;
    input_data.size = 5;
	input_data.array = (int*)malloc(5*sizeof(int));
	for(int i=0; i<5; i++)
        input_data.array[i] = i+1;
	
    uint32_t bytes;
    void* serbuf = ser(&input_data, &bytes);
    free(serbuf);

	vaccel_add_deser_arg(read, &input_data, 0, ser);
    REQUIRE(read->size == 2);
    REQUIRE(read->list[1].size == bytes);
    REQUIRE(read->list[1].argtype == 0);
    REQUIRE(read->list[1].buf != NULL);

    /*
    * What we expect by the plugin to do, is returning 
    * an integer, that is, 'input_int' multiplied by 2, and
    * also an instance of 'struct mydata' with the same size, 
    * but the number that were previously given are now reversed.
    * 
    * e.g. 
    * integer: 10 -> 20
    * 'struct mydata': 1 2 3 4 5 -> 5 4 3 2 1
    * 
    */

    int output_int;
    vaccel_expect_ser_arg(write, &output_int, sizeof(int));
    REQUIRE(write->size == 1);
    REQUIRE(write->list[0].size == sizeof(int));
    REQUIRE(write->list[0].argtype == 0);
    REQUIRE(write->list[0].buf == &output_int);

    vaccel_expect_deser_arg(write);
    REQUIRE(write->size == 2);
    REQUIRE(write->list[1].size == 0);
    REQUIRE(write->list[1].argtype == 0);


	for (int i = 0; i < atoi(iterations); ++i) {
		ret = vaccel_exec(&sess, "../examples/libmytestlib.so",
				"mytestfunc_both", read->list, read->size, write->list, write->size);
		REQUIRE(ret == VACCEL_OK);
	}

    
    // check integer-output correctness
    //REQUIRE(output_int == 20);
    
    // check vaccel_extract_ser_arg()
    int* ptr_out_int = (int*)vaccel_extract_ser_arg(write->list, 0);
    int resp = *ptr_out_int;
    //REQUIRE(resp == 20);

    // check vaccel_extract_deser_arg() and non-ser response correnctness
    struct mydata* out_mydata;
    out_mydata = (struct mydata*)vaccel_extract_deser_arg(write->list, 1, deser);
    REQUIRE(out_mydata->size == 5);
    REQUIRE(out_mydata->array != NULL);

    REQUIRE(out_mydata->array[0] == 5);
    REQUIRE(out_mydata->array[1] == 4);
    REQUIRE(out_mydata->array[2] == 3);
    REQUIRE(out_mydata->array[3] == 2);
    REQUIRE(out_mydata->array[4] == 1);


    delete_arg_list(read);
 	delete_arg_list(write);

    
    if (vaccel_sess_free(&sess) != VACCEL_OK) {
    	fprintf(stderr, "Could not clear session\n");
 		printf("%d\n", 1);
 	}

 	printf("%d\n", ret);
}
