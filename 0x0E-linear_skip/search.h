#ifndef H_SKIP_LIST
#define H_SKIP_LIST

/** Libraries */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/** Prototypes */

/** Primary */
skiplist_t *linear_skip(skiplist_t *list, int value);

/** Complementary */
void free_skiplist(skiplist_t *list);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
#endif
