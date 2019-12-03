#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	int root = 0;

	if (node && !(node->parent))
		root = 1;

	return (root);
}

/**
 * binary_tree_sibling - find the sibling of a node
 *
 * @node: node
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left != node)
		return (node->parent->left);

	return (node->parent->right);
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (binary_tree_is_root(tree))
		func(tree->n);

	if (tree->left)
		func(tree->left->n);

	if (tree->right)
		func(tree->right->n);

	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}

/*
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	func(tree->n);

	binary_tree_levelorder((const binary_tree_t *)binary_tree_sibling(tree), func);

	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
*/
