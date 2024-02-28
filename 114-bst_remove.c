#include "binary_trees.h"

/**
*bst_remove - remove a node from a bst
*@root: pointer to the root
*@value: value to be removed
*Return: pointer to the new root
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *child;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			child = root->right;
			free(root);
			return (child);
		}
		else if (root->right == NULL)
		{
			child = root->left;
			free(root);
			return (child);
		}
		else
		{
			child = root->right;
			while (child->left  != NULL)
				child = child->left;
			root->n = child->n;
			root->right = bst_remove(root->right, child->n);
		}
	}
	return (root);
}
