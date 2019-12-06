#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - checks if tree is complete
 *
 * @tree: pointer to the tree root
 * @i: node index
 * @cnodes: number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_is_complete - calls to tree_is_complete function
 *
 * @tree: tree root
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}


heap_t *heap_insert(heap_t **root, int value)
{
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_complete(*root))
	{
		printf("Llega\n");
		if ((*root)->left)
			return (heap_insert(&((*root)->left), value));
		else
			return ((*root)->left = binary_tree_node(*root, value));
	}

	if (!binary_tree_is_complete((*root)->left))
	{
		if ((*root)->left)
			return (heap_insert(&((*root)->left), value));
		else
			return ((*root)->left = binary_tree_node(*root, value));
	}

	if ((*root)->right)
		return (heap_insert(&((*root)->right), value));
	else
		return ((*root)->right = binary_tree_node(*root, value));

	return (NULL);
}
