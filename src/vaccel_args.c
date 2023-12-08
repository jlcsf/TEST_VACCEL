
#include "vaccel_args.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vaccel_arg_list* vaccel_args_init(){

    struct vaccel_arg_list* arg_list = 
        (struct vaccel_arg_list*)malloc(sizeof(struct vaccel_arg_list));

    arg_list->size = 0;
    arg_list->list = (struct vaccel_arg*)malloc(0);
    
    return arg_list;
}

void vaccel_add_deser_arg(
    struct vaccel_arg_list* args, 
    void* buf,
    uint32_t argtype,
    void* (*serializer)(void*, uint32_t*))
{
    args->size++;
    args->list = realloc(args->list, 
        args->size * sizeof(struct vaccel_arg));

    uint32_t bytes; 
    int pos = args->size - 1;
    args->list[pos].buf  = serializer(buf, &bytes);
    args->list[pos].size = bytes;
    args->list[pos].argtype = argtype;
}

void vaccel_add_ser_arg(
    struct vaccel_arg_list* args,
    void* buf,
    uint32_t size)
{
    args->size++;
    args->list = realloc(args->list, 
        args->size * sizeof(struct vaccel_arg));

    int pos = args->size - 1;
    args->list[pos].size = size;
    args->list[pos].buf  = buf;
    args->list[pos].argtype = 0;
}


void* vaccel_extract_deser_arg(
    struct vaccel_arg* args, 
    int idx, 
    void* (*deserializer(void*, uint32_t)))
{
    return deserializer(args[idx].buf, args[idx].size);
}

void* vaccel_extract_ser_arg(
    struct vaccel_arg* args, 
    int idx)
{
    return args[idx].buf;
}

void delete_arg_list(struct vaccel_arg_list* args){
    free(args->list);
    free(args);
}


void vaccel_expect_ser_arg(
    struct vaccel_arg_list* args, 
    void* buf,
    uint32_t size)
{
    args->size++;
    args->list = realloc(args->list, 
        args->size * sizeof(struct vaccel_arg));

    int pos = args->size - 1;
    args->list[pos].buf  = buf;
    args->list[pos].size = size;
    args->list[pos].argtype = 0;
}

void vaccel_expect_deser_arg(struct vaccel_arg_list* args){
    args->size++;
    args->list = realloc(args->list, 
        args->size * sizeof(struct vaccel_arg));

    args->list[args->size - 1].size    = 0;
    args->list[args->size - 1].argtype = 0;
}

void vaccel_write_arg(
    struct vaccel_arg *args, 
    int idx, 
    void* buf, 
    int bytes)
{
    memcpy(args[idx].buf, buf, bytes);
}

void vaccel_write_ser_arg(
    struct vaccel_arg* args,
    int idx,
    void* buf
)
{
    memcpy(args[idx].buf, buf, args[idx].size);
}

void vaccel_write_deser_arg(
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