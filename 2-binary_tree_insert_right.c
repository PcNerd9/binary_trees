#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right
 * child of another node
 * @parent:  a pointer to the node to insert the right-child in
 * @value: the value to store i the new node
 *
 * Return: a pointer to the new node created
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);
	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent  = parent;
	new_node->left = NULL;
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
		parent->right = new_node;
	}
	else
	{
		parent->right = new_node;
		new_node->right = NULL;
	}
	return (new_node);
}
