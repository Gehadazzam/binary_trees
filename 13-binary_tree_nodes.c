#include "binary_trees.h"
/**
*binary_tree_nodes - count the nodes with at least one child
*
*@tree: pointer to the root
*
*Return: the height or 0
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_n = 0, right_n = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL
		|| tree->right != NULL)
		/*A NULL pointer is not a node*/
		{
		left_n = binary_tree_nodes(tree->left);
		right_n = binary_tree_nodes(tree->right);
		return (1 + left_n + right_n);
		}
	return (0);
}
