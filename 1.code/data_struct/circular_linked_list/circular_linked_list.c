#include "circular_linked_list.h"
node_t* init_list()
{
    node_t *head = (node_t*)malloc(sizeof(node_t));
    if(head != NULL) {
        head->next = head;
    }
    return head;
}

int is_empty(node_t *head)
{
    return head->next == head;
}


//头插法
int insert_head(node_t *head, data_type_t value)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return ERROR;
    }
    new_node->data = value;
    new_node->next = head->next;
    
    head->next = new_node;
    return OK;
}


//尾插法
int insert_at_tail(node_t *head, data_type_t value)
{
    node_t *temp;
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return ERROR;
    }
    new_node->data = value;
    //new_node->next = NULL;
    temp = head;
    while(temp->next!=head) {
        temp = temp->next;
    }
    new_node->next = head;
    temp->next = new_node;
    return OK;
}

//删除节点
int delete_node(node_t*head, data_type_t value)
{
    node_t *del_node;
    node_t *temp = head;
    while(temp->next != head && temp->next->data != value)
    {
        temp = temp->next;
    }
    if(temp->next == head) {
        printf("Value %d not found.\n", value);
        return ERROR;
    }
    del_node = temp->next;
    temp->next = del_node->next;
    free(del_node);
    return OK;
}

//遍历链表
void traverse_list(node_t *head)
{
    node_t *temp = head->next;
    if(temp == head) {
        printf("list is empty\n");
        return;
    }
    while(temp!=head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

//查找节点
node_t* find_node(node_t *head, data_type_t value)
{
    node_t *temp = head->next;
    while(temp != head && temp->data != value) {
        temp = temp->next;
    }
    return temp;
}

//替换节点数据
int replace_node(node_t *head, data_type_t old_value, data_type_t new_value)
{
    node_t *temp = head->next;
    while(temp!= NULL && temp->data!= old_value) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Value %d not found.\n", old_value);
        return ERROR;
    }
    temp->data = new_value;
    return OK;
}

//释放链表
void free_list(node_t *head)
{
    node_t *temp = head->next;
    node_t *del_node;
    while(temp->next != head) {
        del_node = temp;
        temp = temp->next;
        free(del_node);
    }
    free(head);
    printf("List has been free.\n");
}