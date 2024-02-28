#include "binary_trees.h"

/**
 * helper - help to check if min value and max value
 * @tree: tree to be checked
 * @parent: parent to be checked
 * @new: new to be checked
 * @value_n: value_n
 * Return: int
*/
avl_t *helper(avl_t **tree, avl_t *parent, avl_t **new, int value_n)
{
	int value_b;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value_n));
	if ((*tree)->n > value_n)
	{
		(*tree)->left = helper(&(*tree)->left, *tree, new, value_n);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value_n)
	{
		(*tree)->right = helper(&(*tree)->right, *tree, new, value_n);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	value_b = binary_tree_balance(*tree);
	if (value_b < -1)
	{
		if ((*tree)->right->n < value_n)
			*tree = binary_tree_rotate_left(*tree);
		else if ((*tree)->right->n > value_n)
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}
	else if (value_b > 1)
	{
		if ((*tree)->left->n > value_n)
			*tree = binary_tree_rotate_right(*tree);
		else if ((*tree)->left->n < value_n)
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}
	return (*tree);
}

/**
 * avl_insert - insert a value to avl tree
 * @tree: tree to work with
 * @value: value to be added
 * Return: pointer to the tree
 */
avl_t *avl_insert(avl_t **tree, int value)

{
	avl_t *new = NULL;

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	helper(tree, *tree, &new, value);
	return (new);
}
