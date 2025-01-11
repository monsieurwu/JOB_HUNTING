#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR -1

typedef int data_type_t;

/*定义一个单链表节点结构体 */
typedef struct node {
    data_type_t data;
    struct node *next;
} node_t;

node_t* init_list();
int is_empty(node_t *head);
int insert_at_tail(node_t *head, data_type_t value);
int insert_head(node_t *head, data_type_t value);
int delete_node(node_t*head, data_type_t value);
void traverse_list(node_t *head);
node_t* find_node(node_t *head, data_type_t value);
int replace_node(node_t *head, data_type_t old_value, data_type_t new_value);
void free_list(node_t *head);

