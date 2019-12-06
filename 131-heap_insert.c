#include "binary_trees.h"
#include <stdio.h>

/**
 * height - measures the height of a tree
 *
 * @tree: tree root
 * Return: height
 */
int height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}

void swap(heap_t **arg_node)
{
	heap_t *node_parent, *node, *node_right, *node_left;

	node = *arg_node;
	node_parent = node->parent;

	if (node_parent && node->n > node_parent->n)
	{
		node_right = node->right;
		node_left = node->left;

		if (node_parent->parent)
		{
			if (node_parent->parent->left == node_parent)
				node_parent->parent->left = node;
			else
				node_parent->parent->right = node;
		}

		node->parent = node_parent->parent;

		if (node_parent->left == node)
		{
			if (node_parent->right)
				node_parent->right->parent = node;
			node->right = node_parent->right;
			node->left = node_parent;
		}
		else
		{
			if (node_parent->left)
				node_parent->left->parent = node;
			node->left = node->left;
			node->right = node_parent;
		}

		node_parent->left = node_left;
		if (node_left)
			node_left->parent = node_parent;

		node_parent->right = node_right;
		if (node_right)
			node_right->parent = node_parent;

		node_parent->parent = node;
	}

	*arg_node = node;
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root))
	{
		if ((*root)->left)
		{
			return (heap_insert(&((*root)->left), value));
		}
		else
		{
			(*root)->left = binary_tree_node(*root, value);
			swap();
			return ((*root)->left = binary_tree_node(*root, value));
		}
	}

	if (!binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			return (heap_insert(&((*root)->left), value));
		}
		else
		{
			return ((*root)->left = binary_tree_node(*root, value));
		}
	}

	if ((*root)->right)
		return (heap_insert(&((*root)->right), value));
	else
		return ((*root)->right = binary_tree_node(*root, value));

	return (NULL);
}
