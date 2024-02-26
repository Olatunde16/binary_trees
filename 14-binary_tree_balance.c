#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return(0);

	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((left_height > right_height) ? left_height : right_height);
	}

	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return(0);

	size_t left_height, right_height;

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (int)(left_height - right_height);
}
