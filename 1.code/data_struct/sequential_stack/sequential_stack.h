#include <stdio.h>

#define OK 0          
#define ERROR -1      

#define MAX_SIZE 100  

typedef int data_type_t;


typedef struct {
    data_type_t data[MAX_SIZE]; 
    int top;                    
} stack_t;

void init_stack(stack_t *stack);
int is_empty(stack_t *stack);
int is_full(stack_t *stack);
int push(stack_t *stack, data_type_t value);
int pop(stack_t *stack, data_type_t *value);
int peek(stack_t *stack, data_type_t *value);
