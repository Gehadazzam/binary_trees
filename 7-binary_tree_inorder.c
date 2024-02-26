#include "binary_trees.h"
/**
*binary_tree_inorder - goes through a binary tree using inorder traversal
*
*@tree: pointer to the root
*@func: pointer to function
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func == NULL
		|| tree == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
