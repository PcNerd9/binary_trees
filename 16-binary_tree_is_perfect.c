#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if perfect otherwise return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 1;

	if (!tree)
		return (0);
	if (tree->left)
		is_perfect = binary_tree_is_perfect(tree->left);
	if (tree->right)
		is_perfect = binary_tree_is_perfect(tree->right);
	if (is_perfect)
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
