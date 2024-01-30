#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root mode  of the tree to check
 *
 * Return: 1 if full otherwise return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (!tree)
		return (0);
	if (tree->left)
		is_full = binary_tree_is_full(tree->left);
	if (tree->right)
		is_full = binary_tree_is_full(tree->right);
	if (is_full)
	{
		if ((tree->left && tree->right)
				|| (!tree->left && !tree->right))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
