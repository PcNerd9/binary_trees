#include "binary_trees.h"
#include <stdio.h>

/**
 * bst_search - searches for a value in the Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to earch in the tree
 *
 * Return: a pointer to the node of the value if found
 * otherwise return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	if (!tree)
		return (NULL);
	if (tree->left)
	{
		tmp = tree->left;
		tmp = tmp->parent;
	}
	else if (tree->right)
	{
		tmp = tree->right;
		tmp = tmp->parent;
	}
	while (tmp)
	{
		if (tmp->n > value)
			tmp = tmp->left;
		else if (tmp->n < value)
			tmp = tmp->right;
		else
			return (tmp);
	}
	return (tmp);
}
