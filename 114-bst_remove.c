#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: tree root
 * @value: node value
 * Return: pointer the found node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));

	if (tree && value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}


bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);

	if (node != NULL)
	{
		if (node->right->left)
		{
			node->right->left->right = node->right;
			node->right->left->parent = node->parent;
			node->right->left->left = node->left;

			if (node->left)
				node->left->parent = node->right->left;

			if (root == node)
				root = node->right->left;
			free(node);
		}
		else
		{
			node->right->left = node->left;

			node->right->parent = node->parent;

			if (node->left)
				node->left->parent = node->right;

			if (root == node)
				root = node->right->left;
			free(node);
		}
	}

	return (root);
}
