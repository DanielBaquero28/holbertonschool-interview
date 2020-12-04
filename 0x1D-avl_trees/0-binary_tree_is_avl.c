#include "binary_trees.h"

int tree_is_avl(const binary_tree_t *tree, int *height, int min, int max);

/**
 * binary_tree_is_avl - Checks if @tree is a valid AVL tree or not
 * @tree: Tree that will be checked
 *
 * Return: 1 if it is a valid AVL tree otherwise 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);
	return (tree_is_avl(tree, &height, INT_MIN, INT_MAX));
}

/**
 * tree_is_avl -Complementary function that checks if @tree is a valid AVL tree
 * @tree: Tree that will be checked
 * @height: Height of @tree
 * @min: Minimum value of int
 * @max: Maximum value of int
 * Return: 1 if it is a valid AVL tree otherise 0
 */

int tree_is_avl(const binary_tree_t *tree, int *height, int min, int max)
{
	int height_left, height_right;

	height_left = height_right = 0;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!tree_is_avl(tree->left, &height_left, min, tree->n) ||
	    !tree_is_avl(tree->right, &height_right, tree->n, max))
	{
		return (0);
	}

	*height = MAX(height_left, height_right) + 1;

	return (ABS(height_left - height_right) <= 1);
}
