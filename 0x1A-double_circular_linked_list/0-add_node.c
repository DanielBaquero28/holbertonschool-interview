#include "list.h"


/**
 * create_node - Creates a new node of type List
 * @str: String to be copied to the new node.
 *
 * Return: New node.
 */
List *create_node(char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(str);
		return (NULL);
	}

	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node_end - Inserts a node at the end of the @list.
 * @list: Double pointer to the head of the list.
 * @str: String to copy to the new node
 *
 * Return: Address to the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;
	List *tail_node;

	/** Creating a new node  of type List */
	new_node = create_node(str);
	if(!new_node)
		return (NULL);

	/** Checking if list is empty */
	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		/** Identifying last node */
		tail_node = (*list)->prev;

		new_node->next = *list;
		(*list)->prev = new_node;
		new_node->prev = tail_node;
		tail_node->next = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the start of @list
 * @list: Double pointer to the head of the list.
 * @str: String to copy to the new node
 *
 * Return: Address of the new node or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;
	List *tail_node;

	/** Creating a new node of type List */
	new_node = create_node(str);
	if (!new_node)
		return (NULL);

	/** Checking if list is empty */
	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		/** Identifying last node */
		tail_node = (*list)->prev;

		new_node->next = *list;
		(*list)->prev = new_node;
		new_node->prev = tail_node;
		tail_node->next = new_node;

		*list = new_node;
	}

	return (new_node);
}
