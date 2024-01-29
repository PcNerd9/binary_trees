# Binary Tree Repository

## What is a Binary Tree?

A binary tree is a hierarchical data structure composed of nodes, where each node has at most two children, referred to as the left child and the right child. The topmost node is called the root, and nodes with no children are called leaves.

## Difference between Binary Tree and Binary Search Tree (BST)

A Binary Search Tree (BST) is a specific type of binary tree in which the left subtree of a node contains only nodes with values less than the node's value, and the right subtree contains only nodes with values greater than the node's value. This property ensures efficient searching, insertion, and deletion operations.

## Gain in Time Complexity Compared to Linked Lists

Binary trees offer significant improvements in terms of time complexity compared to linked lists, particularly for searching, insertion, and deletion operations. While linked lists have linear time complexity for these operations, binary trees, especially BSTs, can achieve logarithmic time complexity, leading to faster and more efficient algorithms.

## Depth, Height, and Size of a Binary Tree

- **Depth:** The depth of a node in a binary tree is the length of the path from the root to that node.
- **Height:** The height of a binary tree is the length of the longest path from the root to a leaf node. It represents the depth of the deepest node.
- **Size:** The size of a binary tree is the total number of nodes in the tree.

## Traversal Methods for Binary Trees

There are three main traversal methods to navigate through a binary tree:

1. **In-order Traversal:** Visit the left subtree, then the root, and finally the right subtree.
2. **Pre-order Traversal:** Visit the root, then the left subtree, and finally the right subtree.
3. **Post-order Traversal:** Visit the left subtree, then the right subtree, and finally the root.

## Types of Binary Trees

1. **Complete Binary Tree:** A binary tree in which all levels, except possibly the last, are completely filled, and all nodes are as left as possible.
2. **Full Binary Tree:** A binary tree in which every node has either 0 or 2 children.
3. **Perfect Binary Tree:** A binary tree that is both full and complete, where all leaf nodes are at the same level.
4. **Balanced Binary Tree:** A binary tree in which the height of the left and right subtrees of any node differ by at most one.

## Binary Tree Data Structure

### Basic Binary Tree

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

#Binary Search Tree
typedef struct binary_tree_s bst_t;

#AVL Tree
typedef struct binary_tree_s avl_t;
