#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR -1
#define MAX_SIZE 100

typedef int data_type_t;

/* Structure definition for the sequential list */
struct seq_list {
    data_type_t data[MAX_SIZE]; /* Array to store the elements */
    int length;                  /* Current length of the list */
};
// Function prototypes (assuming these are implemented elsewhere)
int init_seq_list(struct seq_list *list);
int append(struct seq_list *list, int value);
int insert(struct seq_list *list, int index, int value);
int delete(struct seq_list *list, int index);
int search(struct seq_list *list, int value);
int update(struct seq_list *list, int index, int value);
void print_seq_list(struct seq_list *list);