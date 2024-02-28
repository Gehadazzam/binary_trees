#include "binary_trees.h"

/**
*array_to_avl - from an array build an avl tree
*@array: array to convert
*@size: number of elemnts
*Return: pointer to the tree
*/
avl_t *array_to_avl(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
