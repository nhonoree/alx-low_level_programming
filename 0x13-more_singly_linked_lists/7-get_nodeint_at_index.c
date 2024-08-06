#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at a specific index in a listint_t list.
 * @head: A pointer to the head of the list.
 * @index: The index of the node to return.
 *
 * Return: The node at the specified index, or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
