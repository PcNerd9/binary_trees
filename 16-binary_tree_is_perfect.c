#include "binary_trees.h"

/**
 * tree_full - checks if a binary tree is full
 * @tree: a pointer to the binary tree to check
 *
 * Return: 1 if full otherwise return 0
 */
int tree_full(const binary_tree_t *tree)
{
	int right_full = 0, left_full = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_full = tree_full(tree->left);
	if (tree->right)
		right_full = tree_full(tree->right);
	if (!tree->left && !tree->right)
		return (1);
	if (right_full && left_full)
		return (1);
	else
		return (0);
}

/**
 * compute_binary_height - compute the height of a binary tree
 * @tree: a pointer to the tree to compute
 *
 * Return: the computed value
 */
int compute_binary_height(const binary_tree_t *tree)
{
	int leftheight = 0, rightheight = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	if (tree->left)
	{
		leftheight = compute_binary_height(tree->left);
		leftheight++;
	}
	if (tree->right)
	{
		rightheight = compute_binary_height(tree->right);
		rightheight++;
	}
	return ((leftheight > rightheight) ? leftheight : rightheight);
}

/**
 * compute_balance_factor - compute the balance factor of a binary tree
 * @tree: a pointer to the binary tree to compute
 *
 * Return: the computed balance factor
 */
int compute_balance_factor(const binary_tree_t *tree)
{
	int right = 1, left = 1;

	if (!tree)
		return (0);
	if (tree->left)
	{
		left = compute_binary_height(tree->left);
		left++;
	}
	if (tree->right)
	{
		right = compute_binary_height(tree->right);
		right++;
	}
	return (left - right);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if perfect otherwise return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_full = 0;
	int balance_factor = 0;

	is_full = tree_full(tree);
	balance_factor = compute_balance_factor(tree);
	if (is_full && balance_factor == 0)
		return (1);
	else
		return (0);
}
