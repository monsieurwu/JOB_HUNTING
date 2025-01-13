#include "doubly_linked_list.h"
dnode_t* init_list()
{
    dnode_t *head = (dnode_t*)malloc(sizeof(dnode_t));
    if (head != NULL) {
        head->prev = NULL;
        head->next = NULL;
    }
    return head;
}

int is_empty(dnode_t *head)
{
    return head == NULL || head->next == NULL;
}

int insert_at_head(dnode_t *head, data_type_t value)
{
    dnode_t *new_node = (dnode_t*)malloc(sizeof(dnode_t));
    if (new_node == NULL) {
        return ERROR;
    }
    new_node->data = value;
    new_node->next = head->next;
    new_node->prev = head;

    if (head->next != NULL) {
        head->next->prev = new_node;
    }
    head->next = new_node;
    return OK;
}

int insert_at_tail(dnode_t *head, data_type_t value)
{
    dnode_t *temp;
    dnode_t *new_node = (dnode_t*)malloc(sizeof(dnode_t));
    if (new_node == NULL) {
        return ERROR;
    }
    new_node->data = value;

    temp = head;
 
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;

    return OK;
}

int delete_node(dnode_t *head, data_type_t value)
{
    dnode_t *temp = head->next;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return ERROR; 
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return OK;
}

void traverse_list(dnode_t *head)
{
    dnode_t *temp = head->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

dnode_t* find_node(dnode_t *head, data_type_t value)
{
    dnode_t *temp = head->next; 
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    return temp; 
}

int replace_node_data(dnode_t *head, data_type_t old_value, data_type_t new_value)
{
    dnode_t *temp = head->next; 

    while (temp != NULL) {
        if (temp->data == old_value) {
            temp->data = new_value;
            return OK;
        }
        temp = temp->next;
    }

    return ERROR; 
}

void free_list(dnode_t *head)
{
    dnode_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}