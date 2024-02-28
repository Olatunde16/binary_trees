#include "binary_trees.h"
#include <stdlib.h>

avl_t *create_avl_node(avl_t *parent, int *array, int first, int last);
avl_t *sorted_array_to_avl(int *array, size_t size);

/**
 * create_avl_node - Creates a new AVL node.
 *
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
avl_t *create_avl_node(avl_t *parent, int *array, int first, int last)
{
	avl_t *node;
	binary_tree_t *aux;
	int mid = 0;

	if (first <= last)
	{
		mid = (first + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		node = (avl_t *)aux;
		node->left = create_avl_node(node, array, first, mid - 1);
		node->right = create_avl_node(node, array, mid + 1, last);
		return (node);
	}
	return (NULL);
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
	if (array == NULL || size == 0)
		return (NULL);
	return (create_avl_node(NULL, array, 0, ((int)(size)) - 1));
}
