#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using
 * in-order traversal
 *
 * @tree: tree root
 * @func: pointer to a function to call for each node
 * Return: no return
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	binary_tree_inorder(tree->left, func);

	if (tree && tree->left->n < tree->n)
		return (1);

	binary_tree_inorder(tree->right, func);
}
