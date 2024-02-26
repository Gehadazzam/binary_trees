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
