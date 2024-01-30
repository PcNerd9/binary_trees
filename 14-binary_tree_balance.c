#include "binary_trees.h"
#include <stdio.h>

/**
 * compute_height - compute the height of a binary tree
 * @tree: a pointer to the tree to compute it height
 *
 * Return: the computed number
 */
int compute_height(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	if (tree->left)
	{
		left = compute_height(tree->left);
		left++;
	}
	if (tree->right)
	{
		right = compute_height(tree->right);
		right++;
	}
	return ((left > right) ? left : right);
}

/**
 * binary_tree_balance - measures the balance factore of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 *
 * Return: the computed number otherwise return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (!tree)
		return (0);
	if (tree->left)
	{
		left = compute_height(tree->left);
		left++;
	}
	if (tree->right)
	{
		right = compute_height(tree->right);
		right++;
	}
	return (left - right);
}
