#include"linked_list.h"

int main()
{
    node_t *linked_list = init_list();
    node_t *found;
    if(linked_list == NULL) {
        printf("Failed to initialize the linked list.\n");
        return ERROR;
    }
    if(is_empty(linked_list)){
        printf("Linked list is empty.\n");
    } else {
        printf("Linked list is not empty.\n");
    }

    insert_head(linked_list,10);
    insert_head(linked_list,20);
    insert_at_tail(linked_list,30);
    insert_at_tail(linked_list,40);

    printf("Linked list after inserting elements: \n");

    traverse_list(linked_list);

    found = find_node(linked_list, 20);
    if(found!=NULL) {
        printf("Found node with value: %d\n", found->data);
    } else {
        printf("Node with value 30 not found.\n");
    }

    replace_node(linked_list, 20, 6);
    traverse_list(linked_list);


    
    delete_node(linked_list, 6);
    printf("after delete 6:\n");
    traverse_list(linked_list);

    free_list(linked_list);
    printf("Linked list has been freed.\n");
    return 0;

}