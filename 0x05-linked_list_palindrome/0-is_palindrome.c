#include "lists.h"

/**
 * check_palindrome - Checks if a given singly linked list is a palindrome
 * @head: Double pointer to head of linked list
 * @tmp: Pointer to the tail of the linked list
 *
 * Return: 1 if it's a palindrome, otherwise 0
 */

int check_palindrome(listint_t **head, listint_t *tmp)
{
	int check_pal;

	if (tmp == NULL)
		return (1);

	if (check_palindrome(head, tmp->next) == 0)
		return (0);

	check_pal = ((*head)->n == tmp->n);

	*head = (*head)->next;

	return (check_pal);
}

/**
 * is_palindrome - Checks if a linked list is a palindrome or not
 * @head: Head pointer of the linked list
 *
 * Return: 1 if it's a palindrome, otherwise 0
 */

int is_palindrome(listint_t **head)
{
	if (!head || !(*head))
		return (1);

	return (check_palindrome(head, *head));
}
