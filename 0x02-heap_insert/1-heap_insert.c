#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into the Max Binary Heap
 * @root: Pointer that points to the pointer to the head node
 * @value: Value assigned to the new node inserted
 *
 * Return: A pointer to the new node inserted
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	binary_tree_t *p_node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		new_node = *root;
	}
	else
	{
		p_node = parent_insert(*root);

		if (p_node->left && !p_node->right)
		{
			p_node->right = binary_tree_node(p_node, value);
			new_node = p_node->right;
		}

		if (!p_node->left && !p_node->right)
		{
			p_node->left = binary_tree_node(p_node, value);
			new_node = p_node->left;
		}

		new_node = check_tree(new_node);
	}
	return (new_node);
}

/**
 * tree_size - Finds the size of the tree of the parent node
 * @tree: Tree from which the size will be found
 *
 * Return: Size of the tree
 */

size_t tree_size(const binary_tree_t *tree)
{
		size_t size = 0;

		if (!tree)
		{
			return (0);
		}

		size += 1;
		if (tree->left != NULL)
		{
			size += tree_size(tree->left);
		}
		/* If tree is complete not perfect */
		if (tree->right != NULL)
		{
			size += tree_size(tree->right);
		}

		return (size);
}

/**
 * check_tree - Checks if the order of the binary tree is correct,
 * if not, it fixes it
 * @tree: Tree that will be checked if order is alright
 *
 * Return: The correct position of @tree
 */

binary_tree_t *check_tree(binary_tree_t *tree)
{
	int v_tmp = 0, v_tmp2 = 0;

	if (tree != NULL)
	{
		if (tree->parent != NULL)
		{
			if (tree->n > tree->parent->n)
			{
				v_tmp = tree->n;
				v_tmp2 = tree->parent->n;
				tree->parent->n = v_tmp;
				tree->n = v_tmp2;
				return (check_tree(tree->parent));

			}
		}
	}

	return (tree);
}

/**
 * is_perfect - Checks if the tree is perfect or not
 * @tree: Tree that will be reviewed in order to know if it is perfect
 *
 * Return: 0 if not perfect, 1 if it is
 */

int is_perfect(const binary_tree_t *tree)
{
	size_t h_tree1 = 0, h_tree2 = 0;
	size_t a = 1, b = 0;

	if (tree != NULL)
	{
		h_tree1 = binary_tree_height(tree);
		for (; h_tree1 > 0; h_tree1--)
		{
			a = 1;
			h_tree2 = h_tree1;
			while (h_tree2 > 0)
			{
				a *= 2;
				h_tree2 -= 1;
			}
			b += a;
		}
		if (b + 1 == tree_size(tree))
		{
			return (1);
		}
	}
	return (0);
}

/**
 * parent_insert - Finds the parent node where new_node will be inserted
 * @tree: Tree from which we'll find the new parent of new_node
 *
 * Return: Pointer to the new parent node
 */

binary_tree_t *parent_insert(binary_tree_t *tree)
{
	size_t left_tree = 0, right_tree = 0;

	left_tree = tree_size(tree->left);
	right_tree = tree_size(tree->right);

	if (left_tree <= right_tree)
	{
		if (tree->left != NULL)
		{
			return (parent_insert(tree->left));
		}
	}
	else if (left_tree > right_tree && is_perfect(tree->left) == 0)
	{
		if (tree->left != NULL)
		{
			return (parent_insert(tree->left));
		}
	}
	else
	{
		if (tree->right != NULL)
		{
			return (parent_insert(tree->right));
		}
	}

	return (tree);
}

