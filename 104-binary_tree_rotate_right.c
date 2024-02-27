#include "binary_trees.h"
/**
*binary_tree_rotate_right - performs a right-rotation on a binary tree
*
*@tree: tree to be rotated
*
*Return: pointer to the new tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *holder;

	if (!tree || !tree->left)
		return (NULL);
	holder = tree->left;
	tree->left = holder->right;
	if (holder->right != NULL)
		holder->right->parent = tree;
	holder->parent = tree->parent;
	holder->right = tree;
	tree->parent = holder;
	return (holder);
}
