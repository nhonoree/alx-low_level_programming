#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to the address of the head of the list.
 *
 * Return: The number of nodes in the list freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp;
	listint_t *head = *h;

	while (head)
	{
		count++;
		temp = head;
		head = head->next;
		free(temp);

		if (head == *h)
		{
			break;
		}
	}

	*h = NULL;

	return (count);
}
