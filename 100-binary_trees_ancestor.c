#include "binary_trees.h"
#include <stdio.h>

/**
 * is_ancestor - checks if first is the ancestor if second
 * @first: a pointer to the ancestor
 * @second: a pointer to the child
 *
 * Return: 1 if ancestor otherwise return 0
 */
int is_ancestor(binary_tree_t *first, binary_tree_t *second)
{

	if (!first || !second)
		return (0);
	while (second)
	{
		if (first == second)
			return (1);
		second = second->parent;
	}
	return (0);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor_f = NULL, *ancestor_s = NULL;
	binary_tree_t *f = NULL, *s = NULL;
	int value = 0;

	if (!first || !second)
		return (NULL);
	if (first->parent->left == first)
		f = first->parent->left;
	else
		f = first->parent->right;
	if (second->parent->left == second)
		s = second->parent->left;
	else
		s = second->parent->right;
	ancestor_f = f;
	ancestor_s = s;

	while (ancestor_s)
	{
		ancestor_f = f;
		value = is_ancestor(ancestor_s, ancestor_f);
		if (value)
			return (ancestor_s);
		ancestor_s = ancestor_s->parent;
	}
	ancestor_f = f;
	ancestor_s = s;
	while (ancestor_f)
	{
		ancestor_s = s;
		value = is_ancestor(ancestor_f, ancestor_s);
		if (value)
			return (ancestor_f);
		ancestor_f = ancestor_f->parent;
	}
	return (NULL);
}
