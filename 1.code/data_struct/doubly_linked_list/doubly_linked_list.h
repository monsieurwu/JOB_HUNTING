#include <stdio.h>
#include <stdlib.h>

#define OK 0          
#define ERROR -1      

typedef int data_type_t;


typedef struct dnode {
    data_type_t data;       
    struct dnode *prev;     
    struct dnode *next;     
} dnode_t;

dnode_t* init_list();
int is_empty(dnode_t *head);
int insert_at_head(dnode_t *head, data_type_t value);
int insert_at_tail(dnode_t *head, data_type_t value);
int delete_node(dnode_t *head, data_type_t value);
void traverse_list(dnode_t *head);
dnode_t* find_node(dnode_t *head, data_type_t value);
int replace_node_data(dnode_t *head, data_type_t old_value, data_type_t new_value);
void free_list(dnode_t *head);