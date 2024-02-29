#include "binary_trees.h"
/**
 * heap_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t heap_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (!tree)
        return (0);

    height_left = heap_tree_height(tree->left);
    height_right = heap_tree_height(tree->right);

    if (height_left > height_right)
        return (height_left + 1);
    else
        return (height_right + 1);
}

/**
 * heap_tree_preorder - Traverses a binary tree in preorder
 * @root: Pointer to the root node of the tree
 * @tree: Pointer to the current node in the traversal
 * @h: Height of the tree
 */
void heap_tree_preorder(heap_t *root, heap_t **tree, size_t h)
{
    if (!tree)
        return;

    if (h == 0)
        *tree = root;

    h--;

    heap_tree_preorder(root->left, tree, h);
    heap_tree_preorder(root->right, tree, h);
}

/**
 * heap_helper - Fixes the heap property after extracting the root
 * @root: Pointer to the root node of the tree
 */
void heap_helper(heap_t *root)
{
    int value;
    heap_t *tmp1, *tmp2;

    if (!root)
        return;

    tmp1 = root;

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
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 if failed
 */
int heap_extract(heap_t **root)
{
    heap_t *tree;
    size_t v;

    if (!root || !*root)
        return (0);

    v = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (v);
    }

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

