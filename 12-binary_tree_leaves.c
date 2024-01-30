#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count
 *
 * Return: the counted number otherwise return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);
	if (!tree->left && !tree->right)
		return (count + 1);
	else
		return (count);
}
