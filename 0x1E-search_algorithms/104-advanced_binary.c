#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursively searches for a value using binary search.
 * @array: Pointer to the first element of the array.
 * @left: Left index of the range.
 * @right: Right index of the range.
 * @value: The value to search for.
 *
 * Return: The index where value is found, or -1.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    if (left > right)
        return (-1);

    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");

    size_t mid = left + (right - left) / 2;

    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);
    if (array[mid] >= value)
        return (advanced_binary_recursive(array, left, mid, value));
    return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value using Advanced Binary search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if not found or NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
