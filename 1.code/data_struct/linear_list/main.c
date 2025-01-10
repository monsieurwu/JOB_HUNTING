#include "seq_list.h"

int main(void) {
    int pos;
    struct seq_list list;

    // Initialize the sequential list
    if (init_seq_list(&list) == ERROR) {
        printf("Failed to initialize the sequential list.\n");
        return ERROR;
    }

    // Add some elements
    append(&list, 10);
    append(&list, 20);
    append(&list, 30);
    append(&list, 40);
    printf("After append:\n");
    print_seq_list(&list);

    // Insert an element at position 2
    insert(&list, 2, 25);
    printf("After insert 25 at index[2]:\n");
    print_seq_list(&list);

    // Delete the element at position 3
    delete(&list, 3);
    printf("After delete at index[3]:\n");
    print_seq_list(&list);

    // Search for the element 20
    pos = search(&list, 20);
    if (pos != ERROR) {
        printf("Element 20 found at position %d\n", pos);
    } else {
        printf("Element 20 not found.\n");
    }

    // Update the element at position 2
    update(&list, 2, 99);
    printf("After update at index[2] to 99:\n");
    print_seq_list(&list);

    return 0;
}