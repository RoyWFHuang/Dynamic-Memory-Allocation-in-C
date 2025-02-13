#include <stdio.h>
#include "include/calloc.h"
#include "include/malloc.h"
#include "include/realloc.h"
#include "include/free.h"
#include "include/metadata.h"

#ifdef MY_MM


#define malloc my_malloc
#define free my_free
#define calloc my_calloc
#define realloc my_realloc
#else
#include <stdlib.h>
#endif
/*
 * Testing code to test all the functions implemented.
 * First two new variables are created and allocated space using my_malloc()
 * Then the first varaible is freed and my_malloc() is called again to show that space can be reused.
 * Then my_calloc() is used to allocate an int array of size 5. Initially the values will be set to 0 by my_calloc();
 * Then the array is resized to size 10 using my_realloc()
 */

int main(){

    printf("\n\n");

    printf("Initializing first variable : ");
    int *a = (int *)malloc(sizeof(int));
    *a = 5;
    printf("%p -> %d \n\n", a, *a);

    printf("Initializing second variable : ");
    int *b = (int *)malloc(sizeof(int));
    *b = 10;
    printf("%p -> %d \n\n", b, *b);

    free(a);
    printf("Freeing first variable and using that memory block again using malloc() for third variable: ");
    int *c = (int *)malloc(sizeof(int));
    printf("%p -> %d \n\n", c, *c);
    printf("Initializing int array of size 5 using calloc() : ");
    int *arr = (int *)calloc(sizeof(int),5);
    printf("%p ->  ",arr);
    for(int i=0; i<5; i++){
        printf(" %d ", *(arr+i));
    }
    printf("\n\n");

    printf("Resizing it to size 10 using realloc(): ");
    arr = (int *)realloc(arr, 10);
    printf("%p ->  ",arr);
    for(int i=0; i<10; i++){
        printf(" %d ", *(arr+i));
    }

    printf("\n\n");

    return 0;
}