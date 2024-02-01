#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - Function goes through a binary tree cheking ropt as max value
 * @tree: Fetches the pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_maxi(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = check_maxi(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_maxi(tree->right);
	}
	return (tmp1 && tmp2);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (tree == NULL)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (check_maxi(tree));
}
