#include "binary_trees.h"

/**
*binary_tree_depth - get the depth of the tree
*
*@tree: pointer to the root
*
*Return: the height or 0
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (tree == NULL)
		return (0);
	while (tree != NULL)
	{
		d++;
		tree = tree->parent;
	}
	return (d - 1);
}

/**
 * binary_tree_uncle - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor
 * node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(
const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_d, second_d;

	if (first == NULL || second == NULL)
		return (NULL);

	first_d = binary_tree_depth(first);
	second_d = binary_tree_depth(second);

	while ((first_d > second_d) || (second_d > first_d))
	{
		if (first_d > second_d)
		{
			first = first->parent;
			first_d--;
		}
		if (second_d > first_d)
		{
			second = second->parent;
			second_d--;
		}
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
