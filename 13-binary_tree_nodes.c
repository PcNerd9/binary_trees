#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * in a binary tree
 * @tree: a pointer to the root node of the tree to count
 *
 * Return: the counted number otherwise return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t counts = 0;

	if (!tree)
		return (0);
	counts += binary_tree_nodes(tree->left);
	counts += binary_tree_nodes(tree->right);
	if (tree->left || tree->right)
		return (counts + 1);
	else
		return (counts);
}
