#include "binary_trees.h"
/**
*binary_tree_is_root - checkes if the node is root
*
*@node: pointer to the node to be checked
*
*Return: 1 or 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL
		|| node->parent != NULL)
		return (0);
	return (1);
}
