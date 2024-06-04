#ifndef __metadata_H__
#define __metadata_H__
#include <stddef.h>


typedef struct meta_block *meta_ptr;

#pragma pack(1)
struct meta_block
{
    int free;
    size_t size;
    meta_ptr next;
    meta_ptr prev;
    void *ptr;
    char data[1];
};
#pragma pack()


#define META_BLOCK_SIZE (sizeof(struct meta_block) - sizeof(char[1]))

#endif
