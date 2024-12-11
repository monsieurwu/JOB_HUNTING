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

int init_seq_list(struct seq_list *list)
{
    if (list == NULL)
    {
        return ERROR;
    }

    list->length = 0;
    return OK;
}

void print_seq_list(struct seq_list *list)
{
    int i;
    printf("sequential list:\n");
    for (i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int append(struct seq_list *list, data_type_t value)
{
    if (list->length < MAX_SIZE)
    {
        list->data[list->length] = value;
        list->length++;
        return OK;
    }
    else
    {
        printf("Sequential list is full, cannot insert new element.\n");
        return ERROR;
    }
}

int insert(struct seq_list *list, int position, data_type_t value)
{
    int i;

    if (list->length >= MAX_SIZE)
    {
        printf("Sequential list is full, cannot insert new element.\n");
        return ERROR;
    }
    if (position < 0 || position > list->length)
    {
        printf("Invalid position.\n");
        return ERROR;
    }

    for (i = list->length; i > position; i--)
    {
        list->data[i] = list->data[i - 1];
    }

    list->data[position] = value;
    list->length++;
    return OK;
}

int delete(struct seq_list *list, int position)
{
    int i;

    if (position < 0 || position >= list->length)
    {
        printf("Invalid position.\n");
        return ERROR;
    }

    for (i = position; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->length--;
    return OK;
}

int search(struct seq_list *list, data_type_t value)
{
    int i;

    for (i = 0; i < list->length; i++)
    {
        if (list->data[i] == value)
        {
            return i;
        }
    }
    return ERROR;
}

int update(struct seq_list *list, int position, data_type_t new_value)
{
    if (position < 0 || position >= list->length)
    {
        printf("Invalid position.\n");
        return ERROR;
    }
    list->data[position] = new_value;
    return OK;
}
