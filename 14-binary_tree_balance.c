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
size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);
	return ((left_h > right_h) ? (left_h + 1) : (right_h + 1));
}
/**
*binary_tree_balance - get the balance of the tree
*
*@tree: pointer to the root
*
*Return: the balance or 0
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);
	return ((int)(left_h - right_h));
}
