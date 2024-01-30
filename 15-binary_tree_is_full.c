#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root mode  of the tree to check
 *
 * Return: 1 if full otherwise return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_is_full = 0, right_is_full = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_is_full = binary_tree_is_full(tree->left);
	if (tree->right)
		right_is_full = binary_tree_is_full(tree->right);
	if (!tree->left && !tree->right)
		return (1);
	if (left_is_full && right_is_full)
		return (1);
	else
		return (0);
}
