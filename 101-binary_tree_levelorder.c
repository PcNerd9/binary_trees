#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert - insert a node to a queue
 * @queue: a pointer to the queue data structure
 * @node: a pointer to the node to add
 * @rear: a pointer to the end of the queue
 * @n: the multiplier to the size of the queue
 * @max: the size of the queue
 *
 * Return: nothing
 */
void insert(binary_tree_t **queue, binary_tree_t *node,
		int *rear, int *n, int max)
{
	queue[(*rear)] = node;
	(*rear)++;
	if (*rear == max - 1)
	{
		queue = realloc(queue, sizeof(binary_tree_t) * max * (*n));
		(*n)++;
	}
	queue[*rear] = NULL;
}

/**
 * pop - remove a node from the queue
 * @queue: a pointer to the queue data structure
 * @front: a pointer to the front of the queue
 *
 * Return: the node
 */
binary_tree_t *pop(binary_tree_t **queue, int *front)
{
	binary_tree_t *node = NULL;

	if (*front == -1)
		*front = 0;
	node =  (queue[*front]);
	(*front)++;

	return (node);
}

/**
 * delete_queue - delete a queue data structure
 * @queue: a pointer to the queue to delete
 *
 * Return: nothing
 */
void delete_queue(binary_tree_t **queue)
{
	free(queue);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to the function to call for each node.
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = -1, rear = 0, max = 100, n = 2;
	binary_tree_t **queue = NULL;
	const binary_tree_t *temp_node = NULL;

	queue[rear] = NULL;
	if (!tree || !func)
		return;
	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * max);
	temp_node = tree;
	while (temp_node)
	{
		func(temp_node->n);
		if (temp_node->left)
			insert(queue, temp_node->left, &rear, &n, max);
		if (temp_node->right)
			insert(queue, temp_node->right, &rear, &n, max);
		temp_node = pop(queue, &front);
	}
	delete_queue(queue);
}
