#include <stddef.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 *
 * Return: the computed number otherwise return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hightleft = 0, heightright = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	if (tree->left)
		hightleft += binary_tree_height(tree->left);
	if (tree->right)
		heightright += binary_tree_height(tree->right);
	if (hightleft > heightright)
	{
		return (hightleft + 1);
	}
	else
		return (heightright + 1);
}
