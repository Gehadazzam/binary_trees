#include "binary_trees.h"
/**
*binary_tree_delete - delete the entire tree and free memory
*
*@tree: pointer to the tree
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	/*recursion*/
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
