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
	heap_t *parent, *aux, *aux2, *node;

	node = *arg_node;
	parent = node->parent;

	if (parent && node->n > parent->n)
	{
		if (node == parent->right)
		{
			aux = parent->left;
			aux2 = parent->parent;

			parent->right = node->right;
			if (node->right)
				node->right->parent = parent;
			parent->left = node->left;
			if (node->left)
				node->left->parent = parent;

			node->right = parent;
			node->left = aux;
			if (aux)
				aux->parent = node;
			parent->parent = node;
			node->parent = aux2;
			if (aux2 && parent == aux2->left)
				aux2->left = node;
			else if (aux2 && parent == aux2->right)
				aux2->right = node;
		}
		else if (node == parent->left)
		{
			aux = parent->right;
			aux2 = parent->parent;

			parent->right = node->right;
			if (node->right)
				node->right->parent = parent;
			parent->left = node->left;
			if (node->left)
				node->left->parent = parent;

			node->left = parent;
			node->right = aux;
			if (aux)
				aux->parent = node;
			parent->parent = node;
			node->parent = aux2;
			if (aux2 && parent == aux2->left)
				aux2->left = node;
			else if (aux2 && parent == aux2->right)
				aux2->right = node;
		}
	}
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			return (heap_insert(&((*root)->left), value));
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			swap(&((*root)->left));
			return (new_node);
		}
	}

	if ((*root)->right)
		return (heap_insert(&((*root)->right), value));
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		swap(&((*root)->right));
		return (new_node);
	}

	return (NULL);
}
