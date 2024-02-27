#include "binary_trees.h"
/**
*binary_tree_rotate_left - performs a left-rotation on a binary tree
*
*@tree: tree to be rotated
*
*Return: pointer to the new tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *holder;

	if (!tree || !tree->right)
		return (NULL);
	holder = tree->right;
	tree->right = holder->left;
	if (holder->left != NULL)
		holder->left->parent = tree;
	holder->parent = tree->parent;
	holder->left = tree;
	tree->parent = holder;
	return (holder);
}
