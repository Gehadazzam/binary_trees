#include "binary_trees.h"
/**
*binary_tree_size - get the size of the tree
*
*@tree: pointer to the root
*
*Return: the height or 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_s = 0, right_s = 0;

	if (tree == NULL)
		return (0);
	left_s = binary_tree_size(tree->left);
	right_s = binary_tree_size(tree->right);
	return (left_s + right_s + 1);
}
