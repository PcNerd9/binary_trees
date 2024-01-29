#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_insert_left - insert a node as the left-child
 * of another node
 * @parent: a pointer to the parent node
 * @value: the value to store in the new node
 * Return: a pointer to the newly created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
		parent->left = new_node;
	}
	else
	{
		parent->left = new_node;
		new_node->left = NULL;
	}

	return (new_node);
}
