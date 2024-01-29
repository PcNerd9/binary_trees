#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - create a new node to add to the binary tree
 * @parent: a pointer to the parent node of the new node
 * @value: the value to store in the new node created
 * Return: a pointer to the new node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
