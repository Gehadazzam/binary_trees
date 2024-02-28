#include "binary_trees.h"
/**
 * helper_sorted - recursive helper function for sorted_array_to_avl
 * @array: pointer to the first element of the array
 * @parent: pointer to the parent node
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 * Return: pointer to the root node of the created AVL tree
 * or NULL on failure
 */
void helper_sorted(int *array, avl_t **parent, size_t min, size_t max)
{
	avl_t *childs = NULL;
	size_t mid, i = max - min;

	if (i > 1)
	{
		mid = (max + min) / 2;
		childs = binary_tree_node(*parent, array[mid]);
		if (array[mid] < (*parent)->n)
			(*parent)->left = childs;
		else if (array[mid] > (*parent)->n)
			(*parent)->right = childs;
		helper_sorted(array, &childs, min, mid);
		helper_sorted(array, &childs, mid, max);
	}
}
/**
*sorted_array_to_avl - builds an avl tree from an array
*@array: array to be converted
*@size: number of elemnets
*Return: pointer to the avl tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t mid;

	if (array == NULL || size == 0)
		return (NULL);
	mid = (size - 1) / 2;
	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);
	helper_sorted(array, &root, -1, mid);
	helper_sorted(array, &root, mid, size);
	return (root);
}
