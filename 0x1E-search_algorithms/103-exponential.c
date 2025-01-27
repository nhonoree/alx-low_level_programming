#include "search_algos.h"

/**
 * binary_search - Performs binary search within a range.
 * @array: Pointer to the first element of the array.
 * @left: Left index of the range.
 * @right: Right index of the range.
 * @value: The value to search for.
 *
 * Return: The index where value is found, or -1.
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    while (left <= right)
    {
        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        mid = left + (right - left) / 2;

        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}

/**
 * exponential_search - Searches for a value using Exponential search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if not found or NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (!array || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t left = bound / 2;
    size_t right = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", left, right);
    return (binary_search(array, left, right, value));
}
