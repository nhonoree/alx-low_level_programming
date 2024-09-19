#include "lists.h"
#include <stdlib.h>  /* For malloc */

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 * @head: A double pointer to the head of the list
 * @n: The integer to be added to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	/* Update the previous head node's prev to point to the new node */
	if (*head != NULL)
		(*head)->prev = new_node;

	/* Set the new node as the head */
	*head = new_node;

	return (new_node);
}
