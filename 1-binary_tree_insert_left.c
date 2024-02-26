#include "binary_trees.h"
/**
*binary_tree_insert_left -  inserts a node as the left-child of another node
*
*@parent: pointer to the binary tree
*
*@value: integer to be added
*
*Return: pointer to the new node or NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node = NULL;

	if (parent == NULL)
		return (NULL);
	left_node = malloc(sizeof(binary_tree_t));
	if (left_node == NULL)
		return (NULL);
	left_node->parent = parent, left_node->n = value;
	left_node->right = NULL, left_node->left = NULL;
	if (parent->left != NULL)
	{
		left_node->left = parent->left;
		left_node->left->parent = left_node;
	}
	parent->left = left_node;
	return (left_node);
}
