#include "binary_trees.h"

/**
*bst_insert - inserts a value to a Binary searsh tree
*@tree: tree to work in
*@value: integer to be added
*Return: pointer to the tree
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));
    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
            return ((*tree)->left = binary_tree_node(*tree, value));
        else
            return (bst_insert(&((*tree)->left), value));
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
            return ((*tree)->right = binary_tree_node(*tree, value));
        else
            return (bst_insert(&((*tree)->right), value));
    }
    return (NULL);
}
