#include "binary_trees.h"

avl_t *create_avl_node(avl_t *parent, int value);

/**
 * create_avl_node - Creates a new AVL node.
 *
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t node;

	*node = binary_tree_node(parent, value);

	if (!node)
		return (NULL);

	node->parent = parent;
	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == NULL)
		return (NULL);

	return (create_avl_node(NULL, array[size / 2]));
}
