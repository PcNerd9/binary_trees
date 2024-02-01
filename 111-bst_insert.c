#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: a double pointer to the root nqode of the bst to
 * insert the value
 * @value: the vale to store in the node to be inserted
 *
 * Return: the pointer to the newly created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *tmp = NULL;

	if (tree == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	tmp = *tree;

	while (tmp)
	{
		if (value < tmp->n)
		{
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				tmp->left = new_node;
				new_node->parent = tmp;
				return (new_node);
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				tmp->right = new_node;
				new_node->parent = tmp;
				return (new_node);
			}
		}
		else
		{
			free(new_node);
			return (NULL);
		}
	}
	*tree = new_node;
	return (new_node);
}
