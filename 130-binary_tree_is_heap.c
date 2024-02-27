#include "binary_trees.h"
/**
*binary_tree_size - get the size of the tree
*
*@tree: pointer to the root
*
*Return: the height or 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_s = 0, right_s = 0;

	if (tree == NULL)
		return (0);
	left_s = binary_tree_size(tree->left);
	right_s = binary_tree_size(tree->right);
	return (left_s + right_s + 1);
}
/**
*helper - help to check if the tree complete
*@t: tree to be checked
*@idx: size
*@s: size of the tree
*Return: int
*/
int helper(const binary_tree_t *t, size_t idx, size_t s)
{
	int left_c = 0, right_c = 0;

	if (t == NULL)
		return (1);
	if (idx >= s)
		return (0);
	left_c = helper(t->left, 2 * idx + 1, s);
	right_c = helper(t->right, 2 * idx + 2, s);
	return (left_c && right_c);
}
/**
*binary_tree_is_complete - checks if the tree is complete
*
*@tree: pointer to the tree to be checked
*
*Return: 0 or 1
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree == NULL)
		return (0);
	s = binary_tree_size(tree);
	return (helper(tree, 0, s));

}

/**
*binary_tree_is_heap - checks if the tree is a valid heap
*@tree: tree to be checked
*Return: 0 or 1
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!binary_tree_is_complete(tree))
		return (0);
	if (tree->left != NULL)
		if (tree->left->n > tree->n
			|| !binary_tree_is_heap(tree->left))
			return (0);
	if (tree->right != NULL)
		if (tree->right->n > tree->n
			|| !binary_tree_is_heap(tree->right))
			return (0);
	return (1);
}
