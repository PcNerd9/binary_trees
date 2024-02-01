#include "binary_trees.h"
#include <stdio.h>

/**
 * max_in_left_node - compute the maximum number in the left side of a node
 * @tree: a pointer to the node to find its max in the left side
 *
 * Return: the maximum number found
 */
int max_in_left_node(binary_tree_t *tree)
{
	int max_left = 0, max_right = 0, value = 0;

	if (!tree)
		return (0);
	max_left = max_in_left_node(tree->left);
	max_right = max_in_left_node(tree->right);
	if (max_left > max_right)
		value = max_left;
	else
		value = max_right;
	if (value < tree->n)
		value = tree->n;
	return (value);

}

/**
 * min_in_right_node - compute the minimum number in the right side
 * of a node
 * @tree:  a pointer to the node to find its min number
 *
 * Return: a min found
 */
int min_in_right_node(binary_tree_t *tree)
{
	int min_left = 0, min_right = 0, value = 100000000;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (tree->n);
	if (tree->left && !tree->right)
		value = tree->left->n;
	if (tree->right && !tree->left)
		value = tree->right->n;
	if (tree->right && tree->left)
	{
		min_left = min_in_right_node(tree->left);
		min_right = min_in_right_node(tree->right);
		if (min_left < min_right)
			value = min_left;
		else
			value = min_right;
	}
	if (value > tree->n)
		value = tree->n;
	return (value);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary
 * search tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is valid BST and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int max_left = 0, min_right = 0, right = 1, left = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	max_left = max_in_left_node(tree->left);
	min_right = min_in_right_node(tree->right);
	if (max_left > tree->n || min_right < tree->n)
		return (0);
	if (tree->left)
		left = binary_tree_is_bst(tree->left);
	if (tree->right)
		right = binary_tree_is_bst(tree->right);
	return (left && right);
}
