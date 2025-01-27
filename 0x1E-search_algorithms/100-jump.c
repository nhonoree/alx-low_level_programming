#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if not found or NULL.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step, prev = 0;

    if (!array || size == 0)
        return (-1);

    step = sqrt(size);
    while (prev < size && array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        prev += step;
    }

    size_t start = prev - step;
    printf("Value found between indexes [%lu] and [%lu]\n", start, prev);

    for (; start < size && start <= prev; start++)
    {
        printf("Value checked array[%lu] = [%d]\n", start, array[start]);
        if (array[start] == value)
            return (start);
    }

    return (-1);
}
