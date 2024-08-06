#include "lists.h"

/**
 * find_loop - Finds the loop in a listint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: Address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}

	return (NULL);
}

