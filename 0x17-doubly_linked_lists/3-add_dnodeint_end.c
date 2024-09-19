#include "lists.h"
#include <stdlib.h>  /* For malloc */

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: A double pointer to the head of the list
 * @n: The integer to be added to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, make new_node the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse to the end of the list */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* Update the last node's next to point to new_node */
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
