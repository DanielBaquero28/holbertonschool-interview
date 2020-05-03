#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_node - Creates a new node for a binary tree
 * @parent: Parent node of the new node created
 * @value: Value to assign to the new node
 *
 * Return: The new binary tree node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * binary_tree_height - Finds the height of a tree
 * @tree: Tree from which the height will be found
 * Return: Depth of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hleft_sub, hright_sub;

	if (!tree)
		return (0);

	hleft_sub = 0;
	hright_sub = 0;

	if (tree->left)
		hleft_sub = binary_tree_height(tree->left) + 1;
	if (tree->right)
		hright_sub = binary_tree_height(tree->right) + 1;

	if (hleft_sub > hright_sub)
		return (hleft_sub);
	return (hright_sub);
}
