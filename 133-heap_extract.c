#include "binary_trees.h"

/**
 * heap_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t heap_tree_height(const heap_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		height_left = heap_tree_height(tree->left);
	if (tree->right)
		height_right = heap_tree_height(tree->right);
	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * heap_tree_preorder - Goes through a binary tree using pre-order traversal
 * @root: Pointer to the root node
 * @tree: Pointer to store the last level-order node
 * @h: Height of the tree
 */
void heap_tree_preorder(heap_t *root, heap_t **tree, size_t h)
{
	if (root == NULL)
		return;
	if (h == 1)
		*tree = root;
	h--;
	heap_tree_preorder(root->left, tree, h);
	heap_tree_preorder(root->right, tree, h);
}

/**
 * heap_helper - Helps to adjust the heap after extraction
 * @tree: Pointer to the root node of the heap
 */
void heap_helper(heap_t *tree)
{
	heap_t *new, *old;
	int value;

	if (tree == NULL)
		return;
	new = tree;
	while (1)
	{
		if (new->left == NULL)
			break;
		if (new->right == NULL)
			old = new->left;
		else
		{
			if (new->left->n > new->right->n)
				old = new->left;
			else
				old = new->right;
		}
		if (new->n > old->n)
			break;
		value = new->n;
		new->n = old->n;
		old->n = value;
		new = old;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Pointer to the root node of the heap
 * Return: Value of the root node, or 0 if extraction fails
 */
int heap_extract(heap_t **root)
{
	heap_t *tree;
	int value;

	if (root == NULL || *root == NULL)
		return (0);
	value = (*root)->n;
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	heap_tree_preorder(*root, &tree, heap_tree_height(*root));
	(*root)->n = tree->n;
	if (tree->parent->left == tree)
		tree->parent->left = NULL;
	else
		tree->parent->right = NULL;
	free(tree);
	heap_helper(*root);
	return (value);
}
