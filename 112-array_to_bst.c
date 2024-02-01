#include "binary_trees.h"
/**
 * array_to_bst - buids a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be
 * converted
 * @size: the number of elements in the array
 *
 * Return: the root the the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
