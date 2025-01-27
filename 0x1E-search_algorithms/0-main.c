#include <stdio.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int array[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(array) / sizeof(array[0]);
    int value = 30;
    int index;

    index = linear_search(array, size, value);
    printf("Found %d at index: %d\n", value, index);

    return (0);
}
