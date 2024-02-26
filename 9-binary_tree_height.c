#include "binary_trees.h"
/**
*binary_tree_height - measure tree 's height
*
*@tree: pointer to the root
*
*Return: the height or 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_h = 0;
size_t right_h = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_h = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_h = 1 + binary_tree_height(tree->right);
	return ((left_h > right_h) ? left_h : right_h);
}
