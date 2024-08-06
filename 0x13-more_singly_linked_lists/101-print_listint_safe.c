#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow = head, *fast = head;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			break;
		}

		head = head->next;
	}

	return (count);
}
