#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return(0);

	size_t depth = 0;
	const binary_tree_t *current = tree;

	while (current->parent != NULL) 
	{
		depth++;
		current = current->parent;
	}

	return(depth);
}
