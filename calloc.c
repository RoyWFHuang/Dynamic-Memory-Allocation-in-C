#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "include/malloc.h"
#include "include/calloc.h"
#include "include/metadata.h"
#include "include/memlib.h"

/*
 * This file contains the implementaion of the function my_calloc()
 * For the details on my_malloc() and allign4() refer the file malloc.c
 * my_calloc() first creates the required chunk of memory using my_malloc()
 * then it sets the values of each byte to 0 by iterating through it.
 */

void *my_calloc(size_t number, size_t size)
{
    size_t *new;
    size_t s, i;

    new = my_malloc(number * size);

    if (new)
    {

        s = align4(number * size) << 2;

        for (i = 0; i < s; i++)
        {
            new[i] = 0;
        }
    }
    return new;
}