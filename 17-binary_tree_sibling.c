#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the siblings of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling of the node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL;

	if (!node)
		return (NULL);
	parent = node->parent;
	if (!parent)
		return (NULL);
	if (parent->left == node)
		return (parent->right);
	else
		return (parent->left);
}
