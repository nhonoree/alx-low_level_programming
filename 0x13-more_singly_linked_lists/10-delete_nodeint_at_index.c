#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes the node at a specific index in a listint_t list.
 * @head: A pointer to the address of the head of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if it succeeded, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; temp && i < index - 1; i++)
		temp = temp->next;

	if (!temp || !temp->next)
		return (-1);

	prev = temp->next;
	temp->next = prev->next;
	free(prev);

	return (1);
}
