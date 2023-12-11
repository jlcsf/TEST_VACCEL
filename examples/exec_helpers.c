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

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <vaccel.h>
#include "../vaccel_args.h"

int main(int argc, char *argv[])
{
	int ret;
	struct vaccel_session sess;
	int input_int;
	int output_int;

	if (argc < 2) {
		fprintf(stderr, "You must specify the number of iterations\n");
		return 1;
	}

	sess.hint = VACCEL_PLUGIN_DEBUG;
	ret = vaccel_sess_init(&sess, sess.hint);
	if (ret != VACCEL_OK) {
		fprintf(stderr, "Could not initialize session\n");
		return 1;
	}

	printf("Initialized session with id: %u\n", sess.session_id);

	
	struct vaccel_arg_list* read  = vaccel_args_init();
	struct vaccel_arg_list* write = vaccel_args_init();

	input_int = 15;
	vaccel_add_ser_arg(read, &input_int, sizeof(input_int));

	vaccel_expect_ser_arg(write, &output_int, sizeof(output_int));

	for (int i = 0; i < atoi(argv[1]); ++i) {
		ret =
		    vaccel_exec(&sess, 
				"../examples/libmytestlib.so", "mytestfunc", 
				read->list, read->size, 
				write->list, write->size);
		
		if (ret) {
			fprintf(stderr, "Could not run op: %d\n", ret);
			goto close_session;
		}
	}

	int *outptr = vaccel_extract_ser_arg(write->list, 0);

	printf("input     : %d\n", input_int);
	printf("output(2x): %d\n", *outptr);

 close_session:
	delete_arg_list(read);
	delete_arg_list(write);

	if (vaccel_sess_free(&sess) != VACCEL_OK) {
		fprintf(stderr, "Could not clear session\n");
		return 1;
	}

	return ret;
}
