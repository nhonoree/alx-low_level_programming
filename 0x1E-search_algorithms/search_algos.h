#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h> /* for size_t */
#include <math.h>   /* for sqrt */
#include <stdio.h>  /* for printf */

/* Prototypes for search algorithms */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
int ternary_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
