#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a specific index in a listint_t list.
 * @head: A pointer to the address of the head of the list.
 * @index: The index at which to insert the new node.
 * @n: The integer to be added to the new node.
 *
 * Return: The address of the new node, or NULL if it failed or the index is out of range.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	listint_t *new_node, *temp = *head;
	unsigned int i;

	if (index == 0)
		return (add_nodeint(head, n));

	for (i = 0; temp && i < index - 1; i++)
		temp = temp->next;

	if (!temp || (index != 0 && !temp->next))
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
