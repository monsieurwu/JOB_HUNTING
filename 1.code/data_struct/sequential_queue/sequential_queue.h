#include <stdio.h>

#define OK 0          
#define ERROR -1      

#define MAX_SIZE 100  


typedef int data_type_t;


typedef struct {
    data_type_t data[MAX_SIZE];
    int front;
    int rear;
} queue_t;

void init_queue(queue_t *queue);
int is_empty(queue_t *queue);
int is_full(queue_t *queue);
int enqueue(queue_t *queue, data_type_t value);
int dequeue(queue_t *queue, data_type_t *value);
int queue_head(queue_t *queue, data_type_t *value);

