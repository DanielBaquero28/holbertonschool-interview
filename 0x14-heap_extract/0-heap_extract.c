#include "binary_trees.h"

heap_t *last_node(heap_t *root);
int max_depth(heap_t *node);
heap_t *find_last_node(int max_depth, int curr_depth, heap_t *node);
void sift_down(heap_t *node);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the binary heap
 *
 * Return: Value stored in @root (root_node->n)
 */

int heap_extract(heap_t **root)
{
	heap_t *temp;
	heap_t *curr;
	int swp_val;

	curr = *root;

	/** Checking if binary tree exists or is empty */
	if (*root == NULL)
		return (0);

	/** Checking if binary tree has only a root node */
	if (!(curr->left) && !(curr->right))
	{
		swp_val = curr->n;
		free(*root);
		*root = NULL;
		return (swp_val);
	}

	temp = last_node(*root);
	if (temp->parent->right)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;

	swp_val = curr->n;
	curr->n = temp->n;

	sift_down(*root);


	free(temp);
	return (swp_val);
}

/**
 * last_node - Finds the last node of the binary heap
 * @root: Root node of the binary heap
 *
 * Return: Pointer to the last node.
 */

heap_t *last_node(heap_t *root)
{
	int depth;

	depth = max_depth(root);

	return (find_last_node(depth, 1, root));
}

/**
 * max_depth - Finds the max depth of a binary tree
 * @node: Root node of the binary tree
 *
 * Return: Depth of the binary tree
 */

int max_depth(heap_t *node)
{
	int left, right;

	if (!node)
		return (0);

	left = max_depth(node->left);
	right = max_depth(node->right);

	return (((left > right) ? left : right) + 1);
}

/**
 * find_last_node - Finds the node at the end of the binary tree
 * @max_depth: Max depth of the binary tree
 * @curr_depth: Current depth of the binary tree
 * @node: Root node of the binary tree
 * Return: Pointer to the node at the end of the binary tree
 */

heap_t *find_last_node(int max_depth, int curr_depth, heap_t *node)
{
	heap_t *left = NULL, *right = NULL;

	if (curr_depth != max_depth)
	{
		left = find_last_node(max_depth, curr_depth + 1, node->left);
		right = find_last_node(max_depth, curr_depth + 1, node->right);
	}
	else
		return (node);

	return ((right) ? right : left);
}

/**
 * sift_down - Moves the value of @node down the tree by successively
 * exhanging the value with the smaller of it's two children until the value
 * is smaller than both of them or until it reaches a leaf.
 * @node: Node from which the value will be sifted down the binary tree
 * Return: Void
 */

void sift_down(heap_t *node)
{
	heap_t *temp_greater = NULL;
	int temp_val;

	/** We're double checking if each subtree is well organized */

	/** If the subtree has two childs */
	if (node->right)
		temp_greater = ((node->right->n > node->left->n)
				? node->right : node->left);
	else if (node->left)
		temp_greater = node->left;

	if (temp_greater)
	{
		if (temp_greater->n > node->n)
		{
			temp_val = temp_greater->n;
			temp_greater->n = node->n;
			node->n = temp_val;
			sift_down(temp_greater);
		}
	}
}
