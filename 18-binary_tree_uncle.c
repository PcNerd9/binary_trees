#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle otherwise return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent = NULL, *grandparent = NULL;

	if (!node)
		return (NULL);
	parent = node->parent;
	if (!parent)
		return (NULL);
	grandparent = parent->parent;
	if (!grandparent)
		return (NULL);
	if (grandparent->left == parent)
		return (grandparent->right);
	else
		return (grandparent->left);
}
