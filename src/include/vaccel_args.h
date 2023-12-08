#ifndef __INCLUDE_VACCEL_ARGS_H__
#define __INCLUDE_VACCEL_ARGS_H__

#include <stddef.h>
#include <stdint.h>

struct vaccel_arg {
	uint32_t argtype;
	uint32_t size;
	void *buf;
};

struct vaccel_arg_list{
    uint32_t size;
    struct vaccel_arg* list;
};

struct vaccel_arg_list* vaccel_args_init();

void vaccel_add_deser_arg(
    struct vaccel_arg_list* args, 
    void* buf, 
    uint32_t argtype,
    void* (*serializer)(void*, uint32_t*)
);

void vaccel_add_ser_arg(
    struct vaccel_arg_list* args,
    void* buf,
    uint32_t size
);

void vaccel_expect_ser_arg(
    struct vaccel_arg_list* args,
    void* buf, 
    uint32_t size
);

void vaccel_expect_deser_arg(struct vaccel_arg_list* args);


void vaccel_write_ser_arg(
    struct vaccel_arg* args,
    int idx,
    void* buf
);

void vaccel_write_deser_arg(
    struct vaccel_arg* args,
    int idx,
    void* buf,
    void* (*serializer)(void*, uint32_t*)
);

void* vaccel_extract_deser_arg(
    struct vaccel_arg* args, 
    int idx, 
    void* (*deserializer(void*, uint32_t))
);

void* vaccel_extract_ser_arg(
    struct vaccel_arg* args, 
    int idx
);

void delete_arg_list(struct vaccel_arg_list* args);

#endif