#include <stdlib.h>
#include "binary_trees.h"

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
    return queue->front == NULL;
}

/**
 * queue_push - Pushes an element to the queue.
 *
 * @queue: A double pointer to the queue where the element will be pushed.
 * @data: A pointer to the data to be pushed.
 */
void queue_push(queue_t **queue, void *data)
{
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
    if (queue_is_empty(*queue))
        return NULL;

    queue_node_t *temp = (*queue)->front;
    void *data = temp->data;

    (*queue)->front = (*queue)->front->next;
    free(temp);

    if ((*queue)->front == NULL)
        (*queue)->rear = NULL;

    return data;
}

/**
 * queue_delete - Deletes a queue and frees its memory.
 *
 * @queue: A pointer to the queue to be deleted.
 */
void queue_delete(queue_t *queue)
{
    while (!queue_is_empty(queue))
        queue_pop(&queue);
    free(queue);
}

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 *
 * Description: If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    queue_t *queue = NULL;
    const binary_tree_t *current;

    queue_push(&queue, (void *)tree);

    while (!queue_is_empty(queue))
    {
        current = (const binary_tree_t *)queue_pop(&queue);
        func(current->n);

        if (current->left)
            queue_push(&queue, (void *)current->left);
        if (current->right)
            queue_push(&queue, (void *)current->right);
    }

    queue_delete(queue);
}
