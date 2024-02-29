#include "binary_trees.h"
/**
 * heap_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t heap_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = heap_tree_height(tree->left);
	height_right = heap_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}
/**
*heap_tree_preorder - goes through a binary tree using pre-order traversal
*@root: pointer to the root
*@tree: pointer to function
*@h: height
*/
void heap_tree_preorder(heap_t *root, heap_t **tree, size_t h)
{
	if (tree == NULL)
		return;
	if (h == 0)
		*tree = root;
	h--;
	/*recursioon*/
	heap_tree_preorder(root->left, tree, h);
	heap_tree_preorder(root->right, tree, h);
}
/**
*heap_helper - help to check if min value and max value
*@t: tree to be checked
*Return: int
*/
void heap_helper(heap_t *t)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!t)
		return;

	tmp1 = t;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}
/**
*heap_extract - extract the root node
*@root: pointer to the root
*Return: 0 or the value
*/
int heap_extract(heap_t **root)
{
	heap_t *tree;
	size_t v;

	if (*root == NULL || root == NULL)
		return (0);
	v = (*root)->n;
	if ((*root)->left == NULL && (*root)->right)
		return (v);
	heap_tree_preorder(*root, &tree, heap_tree_height(*root));
	(*root)->n = tree->n;
	if (tree->parent->left)
		tree->parent->left = NULL;
	else
		tree->parent->right = NULL;
	free(tree);
	heap_helper(*root);
	return (v);
}
