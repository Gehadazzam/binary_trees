#include "binary_trees.h"
/**
*binary_tree_preorder - goes through a binary tree using pre-order traversal
*
*@tree: pointer to the root
*@func: pointer to function
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func == NULL
		|| tree == NULL)
		return;
	func(tree->n);
	/*recursioon*/
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
