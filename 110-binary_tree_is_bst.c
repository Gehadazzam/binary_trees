#include "binary_trees.h"

/**
*helper - help to check if min value and max value
*@t: tree to be checked
*@min_v: min value
*@max_v: max value
*Return: int
*/
int helper(const binary_tree_t *t, int min_v, int max_v)
{
	if (t == NULL)
		return (1);
	if (t->n < min_v || t->n > max_v)
		return (0);
	return (helper(t->left, min_v, t->n - 1) &&
		helper(t->right, t->n + 1, max_v));
}

/**
 * binary_tree_is_bst - is the tree is Binary searsh tree
 * @tree: tree to be checked
 * Return: 0 or 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min_v = INT_MIN, max_v = INT_MAX;

	if (tree == NULL)
		return (0);
	return (helper(tree, min_v, max_v));
}
