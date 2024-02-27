#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of node
 * @node:pointer to the node we will check
 * Return: pointer to the node_uncle or null
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	else if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);
	else
		return (NULL);
}
