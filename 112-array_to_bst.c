#include "binary_trees.h"

/**
*array_to_bst - from an array make a bst
*@array: array to work with
*@size: number of element
*Return: pointer to the bst
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (size_t i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
