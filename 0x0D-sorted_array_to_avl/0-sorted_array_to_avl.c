#include "binary_trees.h"


/**
 * make_node - Makes a node and assigns it's parent and value
 * @p: Parent node of the new node
 * @data: Value that will be assigned to the new node
 *
 * Return: The new node created
 */

avl_t *make_node(avl_t *p, size_t data)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = p;
	node->n = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * insert_node - Correctly inserts a node in a AVL tree
 * @array: Array of integers
 * @root: Root node of the tree
 * @i: Index of an element before the half
 * @j: Index of an element after the half
 * Return: Node inserted in the AVL Tree
 */

avl_t *insert_node(int *array, avl_t *root, size_t i, size_t j)
{
	avl_t *node;
	size_t half;

	/** Means the array is more than empty */
	if (i > j)
		return (NULL);

	half = (i + j) / 2;
	node = make_node(root, array[half]);
	if (!node)
		return (NULL);
	if (half != j)
		node->right = (insert_node(array, node, half + 1, j));
	if (half != i)
		node->left = (insert_node(array, node, i, half - 1));
	return (node);
}

/**
 * sorted_array_to_avl - Transforms @array to an AVL Tree
 * @array: Array of integers
 * @size: Number of elements of @array
 * Return: Head node of the AVL Tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (insert_node(array, NULL, 0, size - 1));
}
