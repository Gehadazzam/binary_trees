#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibiling of node
 * @node:pointer to the node we will check
 * Return: pointer to the node_sibling or null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else if (node == node->parent->right)
		return (node->parent->left);
	else
		return (NULL);
}
