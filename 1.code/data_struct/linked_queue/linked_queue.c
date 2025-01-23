#include "linked_queue.h"

void init_queue(queue_t *queue)
{
    queue->front = queue->rear = NULL;
}

int is_empty(queue_t *queue)
{
    return queue->front == NULL;
}

int enqueue(queue_t *queue, data_type_t value)
{
    queue_node_t *new_node = (queue_node_t*)malloc(sizeof(queue_node_t));
    if (!new_node) {
        return ERROR; // �ڴ����ʧ��
    }
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty(queue)) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    return OK;
}

int dequeue(queue_t *queue, data_type_t *value)
{
    queue_node_t *del_node;

    if (is_empty(queue)) {
        return ERROR; 
    }
    del_node = queue->front;
    *value = del_node->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) { 
        queue->rear = NULL;     
    }
    free(del_node);
    return OK;
}

int queue_head(queue_t *queue, data_type_t *value)
{
    if (is_empty(queue)) {
        return ERROR;
    }
    *value = queue->front->data;
    return OK;
}

