#include "binary_trees.h"

/**
 * binary_tree_is_complete - calls to tree_is_complete function
 *
 * @tree: tree root
 * Return: 1 if tree is complete, 0 otherwise
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	new_root = tree->right;
	new_root->left = tree;

	new_root->parent = tree->parent;

	if (tree->right->left)
	{
		tree->right->left->parent = new_root->left;
		tree->right = tree->right->left;
	}
	else
	{
		tree->right = NULL;
	}

	tree->parent = new_root;

	return (new_root);
}
