#include "binary_trees.h"
#include <stdio.h>
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size <= 1)
	{
		return;
	}

	middle = (size / 2);
/*	printf("Size %ld value %d\n", size, array[middle]);*/
	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle - 1]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle, (size - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle - 1]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle, (size - middle), 2);
	}
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);
	root = binary_tree_node(root, array[middle - 1]);

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle, (size - middle), 2);

	return (root);
}
