#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
 * @head: Pointer to the head of the list
 * @index: Index of the node to retrieve (starting from 0)
 *
 * Return: The nth node, or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i = 0;

    /* Traverse the list until we reach the specified index or the end of the list */
    while (head != NULL)
    {
        if (i == index)  /* If we found the desired index */
            return head; /* Return the node */

        head = head->next; /* Move to the next node */
        i++; /* Increment the index counter */
    }

    return NULL; /* If the node at the specified index does not exist */
}
