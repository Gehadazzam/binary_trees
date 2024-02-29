#include "binary_trees.h"


/**
 * heap_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t heap_tree_size(const binary_tree_t *tree)
{
	size_t size_left = 0, size_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		size_left = heap_tree_size(tree->left);
	if (tree->right)
		size_right = heap_tree_size(tree->right);
	return (size_left + size_right + 1);
}

/**
*heap_to_sorted_array - convert an heap tree to an array
*@heap: heap to work with
*@size: store the size of the array
*Return: array
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array = NULL, i = 0;

	if (heap == NULL || size == NULL)
		return (NULL);

	*size = heap_tree_size(heap);
	sorted_array = malloc((*size) * sizeof(int));
	if (sorted_array == NULL)
		return (NULL);
	while (heap)
	{
		sorted_array[i] = heap_extract(&heap);
		i++;
	}
	return (sorted_array);
}
