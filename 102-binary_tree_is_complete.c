#include "binary_trees.h"
#include <stdlib.h>

/**
 * insert_queue - insert a node to a queue data structure
 * @queue: a pointer to the queue data structure
 * @node: a pointer to the node to add
 * @rear: a pointer to the end of the queue
 * @n: a pointer to the multiplier of the size of the queue
 * @max: a pointer to the size of the queue
 *
 * Return: nothing
 */
void insert_queue(binary_tree_t **queue, binary_tree_t *node,
		int *rear, int *n, int max)
{
	queue[(*rear)] = node;
	(*rear)++;
	if ((*rear) == max - 1)
	{
		queue = realloc(queue, sizeof(binary_tree_t) * max * (*n));
		(*n)++;
	}
	queue[(*rear)] = NULL;
}

/**
 * pop - remove a node from the queue data structure
 * @queue: a pointer to the queue data structure
 * @front: a pointer to the beginner of the queue
 *
 * Return: the node removed from the queue
 */
binary_tree_t *pop(binary_tree_t **queue, int *front)
{
	binary_tree_t *node = NULL;

	if (*front == -1)
		(*front) = 0;
	node = queue[(*front)];
	(*front)++;

	return (node);
}

/**
 * delete_queue - delete a queue data structure from the memory
 * @queue: the queue to delete
 *
 * Return: nothing
 */
void delete_queue(binary_tree_t **queue)
{
	free(queue);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the node of the tree to check
 *
 * Return: 1 if complete otherwise return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front = -1, rear = 0, max = 100, n = 2;
	int is_full = 1;
	binary_tree_t **queue = NULL;
	const binary_tree_t *temp_node = NULL;

	if (!tree)
		return (0);
	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * max);
	queue[rear] = NULL;
	temp_node = tree;
	while (temp_node)
	{
		if (!is_full && (temp_node->left || temp_node->right))
		{
			delete_queue(queue);
				return (0);
		}
		if (!temp_node->left && temp_node->right)
		{
			delete_queue(queue);
			return (0);
		}
		if (temp_node->left)
			insert_queue(queue, temp_node->left, &rear, &n, max);
		else
			is_full = 0;
		if (temp_node->right)
			insert_queue(queue, temp_node->right, &rear, &n, max);
		else
			is_full = 0;
		temp_node = pop(queue, &front);
	}
	delete_queue(queue);
	return (1);
}
