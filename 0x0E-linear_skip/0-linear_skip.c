#include "search.h"

skiplist_t *search_sub(skiplist_t *head_sub, skiplist_t *tail_sub, int value);

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 * Return: Pointer to the node where @value was found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL;
	skiplist_t *curr = NULL;
	size_t prev_i, curr_i;

	if (!list)
		return (NULL);
	curr = list;
	while (curr->express)
	{
		prev = curr;
		curr = curr->express;
		prev_i = prev->index;
		curr_i = curr->index;
		printf("Value checked at index [%lu] = [%i]\n", curr->index,
			curr->n);
		/**
		 * Checking if the lowest value of the skip list is greater
		 * than @value
		 */
		if (prev->index == 0 && prev->n > value)
			return (NULL);
		/**
		 * Checking if we possibly have found the
		 * suitable subsequence
		 */
		if (curr->n >= value)
			break;
	}
	/**
	 * Checking if the node where value is found is located in the
	 * last sparse subsequence
	 */
	if (!curr->express && curr->n < value)
	{
		prev = curr;
		prev_i = prev->index;
		/** Making curr point to the tail of the skip list  */
		while (curr->next)
			curr = curr->next;
		curr_i = curr->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev_i, curr_i);
	return (search_sub(prev, curr, value));

}


/**
 * search_sub - Searches and tries to find @value in a sparse
 * subsequence between @head_sub and @tail_sub
 * @head_sub: Pointer to the head of the subsequence
 * @tail_sub: Pointer to the tail of the subsequence
 * @value: Value to search for
 * Return: Pointer to the node where @value was found otherwise NULL
 */

skiplist_t *search_sub(skiplist_t *head_sub, skiplist_t *tail_sub, int value)
{
	while (head_sub && (head_sub->index <= tail_sub->index))
	{
		printf("Value checked at index [%lu] = [%i]\n", head_sub->index,
			head_sub->n);
		/** Checking if the node where n is equal to @value */
		if (head_sub->n == value)
			return (head_sub);
		head_sub = head_sub->next;
	}
	/** If it doesn't find it*/
	return (NULL);
}
