#ifndef H_DOUBLE_CIRCULAR_LINKED_LIST
#define H_DOUBLE_CIRCULAR_LINKED_LIST

/** Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;


/** Prototypes */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
#endif
