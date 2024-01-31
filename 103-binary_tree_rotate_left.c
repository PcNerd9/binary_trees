#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent = NULL;

	if (!tree)
		return (NULL);
	parent = tree->right;
	if (!parent)
		return (NULL);
	parent->parent = tree->parent;
	tree->parent = parent;
	tree->right = parent->left;
	parent->left = tree;
	return (parent);
}
