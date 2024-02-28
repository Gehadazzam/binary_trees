#include "binary_trees.h"

/**
*bst_search - search for a value in a bst
*@tree: tree to work with
*@value: value to search
*Return: pointer of the node containes the value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	while (tree)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
		else
			return ((bst_t *)tree);
	}
	return (NULL);
}
