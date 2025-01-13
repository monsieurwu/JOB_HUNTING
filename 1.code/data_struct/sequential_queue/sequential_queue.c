#include "sequential_queue.h"

void init_queue(queue_t *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int is_empty(queue_t *queue)
{
    return queue->front == queue->rear;
}

int is_full(queue_t *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

int enqueue(queue_t *queue, data_type_t value)
{
    if (is_full(queue)) {
        printf("Queue is full!\n");
        return ERROR;
    }
    queue->data[queue->rear] = value;
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return OK;
}

int dequeue(queue_t *queue, data_type_t *value)
{
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return ERROR;
    }
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return OK;
}

int queue_head(queue_t *queue, data_type_t *value)
{
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return ERROR;
    }
    *value = queue->data[queue->front];
    return OK;
}