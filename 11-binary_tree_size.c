#include "binary_trees.h"

/**
 * binary_tree_size - measures the s ize of a binary  tree
 * @tree: a pointer to the root node of the tree to measure
 *
 * Return: the size otherwise return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);
	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);
	return (left + right + 1);
}
