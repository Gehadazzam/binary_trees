#include "binary_trees.h"
/**
*helper_successor - help to check if node
*@root: tree to be checked
*Return: 0
*/
int helper_successor(bst_t *root)
{
	size_t i = 0;

	if (root == NULL)
		return (0);

	else
	{
		i = helper_successor(root->left);
		if (i == 0)
			return (root->n);
		return (i);
	}
}

/**
*avl_helper - help to check if node
*@root: tree to be checked
*Return: 0
*/
int avl_helper(bst_t *root)
{
	size_t i = 0;

	if (root->left == NULL && root->right == NULL)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((root->left == NULL && root->right) ||
		(root->right == NULL && root->left))
	{
		if (root->left == NULL)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (root->right == NULL)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		i = helper_successor(root->right);
		root->n = i;
		return (i);
	}
}

/**
*bst_remove - remove a node from a bst
*@root: pointer to the root
*@value: value to be removed
*Return: pointer to the new root
*/
bst_t *bst_remove(bst_t *root, int value)
{
	size_t i = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else
	{
		if (value == root->n)
		{
			i = avl_helper(root);
			if (i != 0)
				bst_remove(root->right, i);
		}
		else
			return (NULL);
	}
	return (root);
}
/**
 * balance - function that balances binary search tree
 * @tree: pointer to the root
*/
void balance(avl_t **tree)
{
	int i;

	if (tree == NULL || *tree == NULL ||
	((*tree)->left == NULL && (*tree)->right == NULL))
		return;
	balance(&(*tree)->left);
	balance(&(*tree)->right);
	i = binary_tree_balance((const binary_tree_t *)*tree);
	if ((int)i > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if ((int)i < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
*avl_remove - remove a node from an avl tree
*@root: pointer to the root
*@value: value of the node
*Return: pointer to the root
*/
avl_t *avl_remove(avl_t *root, int value)
{
	root = (avl_t *) bst_remove((bst_t *) root, value);
	if (root == NULL)
		return (NULL);
	balance(&root);
	return (root);
}
