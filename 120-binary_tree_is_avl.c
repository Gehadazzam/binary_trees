#include "binary_trees.h"

/**
 * binary_tree_height - measure tree 's height
 * @tree: pointer to the root
 * Return: the height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return ((left_h > right_h) ? (left_h + 1) : (right_h + 1));
}

/**
*helper - help to check if min value and max value
*@tree: tree to be checked
*@min_v: min value
*@max_v: max value
*Return: int
*/
int helper(const binary_tree_t *tree, int min_v, int max_v)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min_v || tree->n > max_v)
		return (0);
	if (abs(
	(int)(binary_tree_height(tree->left)) -
	(int)(binary_tree_height(tree->right))) > 1)
		return (0);
	return (helper(tree->left, min_v, tree->n - 1) &&
		helper(tree->right, tree->n + 1, max_v));
}

/**
*binary_tree_is_avl - checks if the tree is avl
*@tree: tree to be checked
*Return: 1 or 0
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t min = INT_MIN, max = INT_MAX;

	if (tree == NULL)
		return (0);
	return (helper(tree, min, max));
}
