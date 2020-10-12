#ifndef _H_SINGLY_LIST_
#define _H_SINGLY_LIST_

/** Libraries */
#include <stdio.h>
#include <stddef.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/** Prototypes */
listint_t *find_listint_loop(listint_t *head);

#endif
