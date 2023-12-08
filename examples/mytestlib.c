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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

struct vaccel_arg {
	uint32_t argtype;
	uint32_t size;
	void *buf;
};

struct mydata
{
	uint32_t size;
	int* array;
};


static 
void* 
vaccel_extract_ser_arg(struct vaccel_arg* args, int idx)
{
    return args[idx].buf;
}

static
void 
vaccel_write_ser_arg(struct vaccel_arg* args, int idx, void* buf)
{
    memcpy(args[idx].buf, buf, args[idx].size);
}

static void* vaccel_extract_deser_arg(
    struct vaccel_arg* args, 
    int idx, 
    void* (*deserializer(void*, uint32_t)))
{
    return deserializer(args[idx].buf, args[idx].size);
}

static void vaccel_write_deser_arg(
    struct vaccel_arg* args,
    int idx,
    void* buf,
    void* (*serializer)(void*, uint32_t*)
)
{
    uint32_t bytes;
    
    args[idx].buf     = serializer(buf, &bytes);
    args[idx].size    = bytes;
    args[idx].argtype = 0;
}

void* ser(void* buf, uint32_t* bytes){
	struct mydata* non_ser = (struct mydata*)buf;

	uint32_t size = (non_ser->size + 1) * sizeof(int);
	int* ser_buf = malloc(size);

	memcpy(ser_buf, (int*)(&non_ser->size), sizeof(int));
	
	for(int i=0; i<non_ser->size; i++)
		memcpy(&ser_buf[i+1], &non_ser->array[i], sizeof(int));
	

	*bytes = size;
	return ser_buf;
}


void* deser(void* buf, uint32_t bytes){
	int *ser_buf = (int*)buf;
	int size = ser_buf[0];

	struct mydata* new_buf = 
		(struct mydata*)malloc(sizeof(struct mydata));

	new_buf->size = (uint32_t)size;
	new_buf->array = malloc(new_buf->size * sizeof(int));
	for(int i=0; i<size; i++)
		memcpy(&new_buf->array[i], &ser_buf[i+1], sizeof(int));

	return new_buf;
}
/* We know we're getting only one read and only one write argument */

int mytestfunc(struct vaccel_arg *input, size_t nr_in,
	       struct vaccel_arg *output, size_t nr_out)
{
	assert(nr_in >= 1);
	assert(nr_out >= 1);

	// Input 
	int* input_int = vaccel_extract_ser_arg(input, 0);
	
	printf("I got nr_in: %ld, nr_out: %ld\n", nr_in, nr_out);
	printf("I got this input: %d\n", *input_int);
	
	// Output
	int output_int = 2*(*input_int);
	vaccel_write_ser_arg(output, 0, &output_int);
	return 0;
}

int mytestfunc_nonser(struct vaccel_arg *input, size_t nr_in,
	       struct vaccel_arg *output, size_t nr_out)
{
	assert(nr_in >= 1);
	assert(nr_out >= 1);
	printf("I got nr_in: %ld, nr_out: %ld\n", nr_in, nr_out);
	
	// Input
	struct mydata* input_data = 
		vaccel_extract_deser_arg(input, 0, deser);

	// Copy the numbers 
	int *numbuf = malloc(input_data->size*sizeof(int));
	memcpy(numbuf, input_data->array, input_data->size * sizeof(int));

	// Reverse the numbers
	for(int i=0; i<input_data->size; i++){
		input_data->array[i] = numbuf[input_data->size - i - 1];
	}

	// Output
	struct mydata* output_data = input_data;
	vaccel_write_deser_arg(output, 0, output_data, ser);

	return 0;
}

int mytestfunc_both(struct vaccel_arg *input, size_t nr_in,
	       struct vaccel_arg *output, size_t nr_out)
{
	assert(nr_in >= 1);
	assert(nr_out >= 1);
	printf("I got nr_in: %ld, nr_out: %ld\n", nr_in, nr_out);
	
	// Input 1
	int* input_int = 
		vaccel_extract_ser_arg(input, 0);

	// Input 2
	struct mydata* input_data = 
		vaccel_extract_deser_arg(input, 1, deser);

	// Copy the numbers 
	int *numbuf = malloc(input_data->size*sizeof(int));
	memcpy(numbuf, input_data->array, input_data->size * sizeof(int));

	// Reverse the numbers
	for(int i=0; i<input_data->size; i++){
		input_data->array[i] = numbuf[input_data->size - i - 1];
	}

	// Output 1
	int output_int = *input_int * 2;
	vaccel_write_ser_arg(output, 0, &output_int);

	// Output 2
	struct mydata* output_data = input_data;
	vaccel_write_deser_arg(output, 1, output_data, ser);

	return 0;
}