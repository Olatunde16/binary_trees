#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree != NULL)
	{
		current = *tree;
		if (current == NULL)
		{
			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));
			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (current->left = new);
		}
		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));
			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (current->right = new);
		}
	}

	return (NULL);
}
