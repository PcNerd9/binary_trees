#include <stddef.h>
#include "binary_trees.h"
#include <stdio.h>

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hightleft = 0, heightright = 0;
	if (!tree)
		return (0);
	hightleft = binary_tree_height(tree->left);
	heightright = binary_tree_height(tree->right);
	if (hightleft > heightright)
	{
		printf("hightleft:\t %ld\n", hightleft);
		return (hightleft + 1);
	}
	else
		return (heightright + 1);
		
}
