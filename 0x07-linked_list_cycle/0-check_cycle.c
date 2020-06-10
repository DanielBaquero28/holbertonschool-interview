#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle
 * @list: Pointer to the head of the linked list
 *
 * Return: 1 if there's a cycle, otherwise 0
 */

int check_cycle(listint_t *list)
{
	listint_t *first = NULL;
	listint_t *n_first = NULL;

	if (!list)
		return (0);

	first = n_first = list;

	while (first->next && n_first->next)
	{
		first = first->next;
		n_first = n_first->next->next;

		if (!n_first)
			return (0);
		if (first == n_first)
			return (1);
	}

	return (0);
}
