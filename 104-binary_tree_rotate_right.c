#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tre
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent = NULL;

	if (!tree)
		return (NULL);
	parent = tree->left;
	if (!parent)
		return (NULL);
	parent->parent = tree->parent;
	tree->parent = parent;
	tree->left = parent->right;
	parent->right = tree;
	return (parent);
}
