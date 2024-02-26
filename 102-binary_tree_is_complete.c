#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/* Queue node structure */
typedef struct queue_node {
    void *data;
    struct queue_node *next;
} queue_node_t;

/* Queue structure */
typedef struct queue {
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

queue_t *queue_create(void);
int queue_is_empty(const queue_t *queue);
void queue_push(queue_t **queue, void *data);
void *queue_pop(queue_t **queue);
void queue_delete(queue_t *queue);

/**
 * queue_create - Creates a new queue.
 *
 * Return: A pointer to the newly created queue, or NULL if memory allocation fails.
 */
queue_t *queue_create(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (queue == NULL)
        return NULL;

    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/**
 * queue_is_empty - Checks if a queue is empty.
 *
 * @queue: A pointer to the queue to be checked.
 *
 * Return: 1 if the queue is empty, 0 otherwise.
 */
int queue_is_empty(const queue_t *queue)
{
    return queue == NULL || queue->front == NULL;
}

/**
 * queue_push - Pushes an element to the queue.
 *
 * @queue: A double pointer to the queue where the element will be pushed.
 * @data: A pointer to the data to be pushed.
 */
void queue_push(queue_t **queue, void *data)
{
    if (queue == NULL || data == NULL)
        return;

    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (new_node == NULL)
        return;

    new_node->data = data;
    new_node->next = NULL;

    if ((*queue)->rear == NULL) {
        (*queue)->front = new_node;
        (*queue)->rear = new_node;
    } else {
        (*queue)->rear->next = new_node;
        (*queue)->rear = new_node;
    }
}

/**
 * queue_pop - Pops an element from the queue.
 *
 * @queue: A double pointer to the queue from which the element will be popped.
 *
 * Return: A pointer to the data popped from the queue, or NULL if the queue is empty.
 */
void *queue_pop(queue_t **queue)
{
    if (queue == NULL || queue_is_empty(*queue))
        return NULL;

    queue_node_t *temp = (*queue)->front;
    void *data = temp->data;

    (*queue)->front = (*queue)->front->next;
    if ((*queue)->front == NULL)
        (*queue)->rear = NULL;

    free(temp);
    return data;
}

/**
 * queue_delete - Deletes a queue and frees its memory.
 *
 * @queue: A pointer to the queue to be deleted.
 */
void queue_delete(queue_t *queue)
{
    if (queue == NULL)
        return;

    while (!queue_is_empty(queue))
        free(queue_pop(&queue));
    free(queue);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	queue_t *queue = queue_create();
	if (queue == NULL)
		return (0);
	
	int seen_null = 0;
	queue_push(&queue, (void *)tree);
	
	while (!queue_is_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(&queue);
		
		if (current == NULL)
			seen_null = 1;
		
		else if (seen_null)
		{
			queue_delete(queue);
			return (0);
		}
		
		else
		{
			queue_push(&queue, (void *)current->left);
			queue_push(&queue, (void *)current->right);
		}
	}
	
	queue_delete(queue);
	return (1);
}
