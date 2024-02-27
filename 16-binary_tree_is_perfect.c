#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if the tree is full
 * @tree: pointer to the root
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL
		&& tree->right == NULL)
		return (1);
	if (tree->left == NULL
		|| tree->right == NULL)
		return (0);
	return (binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right));
}

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
 * binary_tree_is_perfect - checks if the tree is perfect
 * @tree: pointer to the root
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t l_height, r_height;

    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    l_height = binary_tree_height(tree->left);
    r_height = binary_tree_height(tree->right);

    if (l_height != r_height)
        return (0);
    return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
}
