#include "doubly_linked_list.h"
int main(void)
{
    dnode_t *linked_list = init_list();
    dnode_t *found;
    if (linked_list == NULL) {
        printf("Failed to initialize the linked_list.\n");
        return ERROR;
    }
    if (is_empty(linked_list)) {
        printf("List is empty\n\n");
    }
    else {
        printf("List not empty\n\n");
    }
    // ����һЩ�ڵ�
    insert_at_head(linked_list, 10);
    insert_at_head(linked_list, 20);
    insert_at_tail(linked_list, 30);
    insert_at_tail(linked_list, 40);

    if (is_empty(linked_list)) {
        printf("List is empyt\n\n");
    }
    else {
        printf("List not empyt\n\n");
    }

    // ��������
    printf("After insert 4 nodes\n");
    traverse_list(linked_list);

    // ���ҽڵ�
    found = find_node(linked_list, 30);
    if (found != NULL) {
        printf("Found node with value: %d\n\n", found->data);
    }
    else {
        printf("Node with value 30 not found.\n\n");
    }
    if (replace_node_data(linked_list, 20, 50) == OK) {
        printf("Replace value 20 to value: 50\n\n");
    }
    printf("List after replace 20 to 50:\n");
    traverse_list(linked_list);

    // ɾ���ڵ�
    delete_node(linked_list, 30);
    printf("List after delete 30:\n");
    traverse_list(linked_list);

    // �ٴ�ɾ���ڵ�
    delete_node(linked_list, 50);
    printf("List after delete 50:\n");
    traverse_list(linked_list);

    // �ͷ������ڴ�
    free_list(linked_list);

    return OK;
}