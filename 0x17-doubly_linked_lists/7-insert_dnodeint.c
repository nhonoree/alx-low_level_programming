#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to the pointer of the head of the list
 * @idx: Index of the list where the new node should be added
 * @n: Data to store in the new node
 * 
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new, *temp = *h;
    unsigned int i = 0;

    if (idx == 0)
        return (add_dnodeint(h, n));

    while (temp != NULL && i < idx - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
        return (NULL);

    if (temp->next == NULL)
        return (add_dnodeint_end(h, n));

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = temp->next;
    new->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new;
    temp->next = new;

    return (new);
}

