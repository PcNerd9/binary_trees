#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is the leaf
 * @node: a pointer to the given node to check
 * Return: 1 if the node is a leaf otherwise return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right && node->parent)
		return (1);
	else
		return (0);
}
