#include "lists.h"
#include <stddef.h>  /* For size_t and NULL */
#include <stdio.h>   /* For printf */

/**
 * print_dlistint - Prints all the elements of a doubly linked list
 * @h: A pointer to the head of the list
 *
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }

    return count;
}
