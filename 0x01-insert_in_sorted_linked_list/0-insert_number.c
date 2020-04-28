#include "lists.h"

/**
 * insert_node - Inserts a new node at the correct order of @head.
 * @head: Double pointer that points to the head of the linked list.
 * @number: Value to insert in @head.
 *
 * Return: The new node inserted.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *tmp_node = NULL;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	if (new_node->n < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		/* return (new_node); */
	}
	else
	{
		tmp_node = *head;
		while (tmp_node != NULL)
		{
			if (tmp_node->next == NULL || new_node->n < tmp_node->next->n)
			{
				new_node->next = tmp_node->next;
				tmp_node->next = new_node;
				break;
			}
			tmp_node = tmp_node->next;
		}
	}

	return (new_node);
}
