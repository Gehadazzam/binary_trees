#include "binary_trees.h"
/**
*array_to_heap - from an array make a heap tree
*@array: array to work with
*@size: number of elements
*Return: pointer to the tree
*/
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);
	while (i < size)
	{
		heap_insert(&tree, array[i]);
		i++;
	}
	return (tree);
}
