#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: Fetches the pointer to the first element of the
 * array to be converted
 * @size: Fetches the number of element in the array
 * Return: The Pointer to root
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	root = avl_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
