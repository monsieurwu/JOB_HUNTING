#include "linked_queue.h"

int main(void)
{
    queue_t queue;
    data_type_t value;

   
    init_queue(&queue);

    if (is_empty(&queue)) {
        printf("Quueue is empyt\n\n");
    }
    else {
        printf("Queue not empyt\n\n");
    }
    
    printf("add [%d] into queue\n", 10);
    enqueue(&queue, 10);
    queue_head(&queue, &value);
    printf("front value of queue is [%d]\n", value);
    printf("add [%d] into queue\n", 20);
    enqueue(&queue, 20);
    queue_head(&queue, &value);
    printf("front value of queue is [%d]\n", value);
    printf("add [%d] into queue\n", 30);
    enqueue(&queue, 30);
    printf("add [%d] into queue\n", 40);
    enqueue(&queue, 40);

    queue_head(&queue, &value);
    printf("front value of queue is [%d]\n", value);

    while (!is_empty(&queue)) {
        dequeue(&queue, &value);
        printf("dequeue value [%d]\n", value);
    }

    return 0;
}