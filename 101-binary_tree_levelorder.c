#include "binary_trees.h"

/**
*binary_tree_height - measure tree 's height
*
*@tree: pointer to the root
*
*Return: the height or 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_h = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_h = 1 + binary_tree_height(tree->right);
	return ((left_h > right_h) ? left_h : right_h);
}

/**
 * helper - goes through a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @l: the level of the tree to func
 */
void helper(const binary_tree_t *tree, void (*func)(int), size_t l)
{
	if (l != 1)
	{
		helper(tree->left, func, l - 1);
		helper(tree->right, func, l - 1);
	}
	else
	{
		func(tree->n);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t l = 1, max;

	if (tree == NULL || func == NULL)
		return;

	max = binary_tree_height(tree) + 1;
	while (l <= max)
	{
		helper(tree, func, l);
		l++;
	}
}
