#include "sequential_stack.h"
void init_stack(stack_t *stack)
{
    stack->top = -1;
}

int is_empty(stack_t *stack)
{
    return stack->top == -1;
}

int is_full(stack_t *stack)
{
    return stack->top == MAX_SIZE - 1;
}

int push(stack_t *stack, data_type_t value)
{
    if (stack->top < MAX_SIZE)
    {
        
        stack->top++;
        stack->data[stack->top] = value;
        return OK;
    }
    else
    {
        printf("Stack is full, cannot push new element.\n");
        return ERROR;
    }
}

int pop(stack_t *stack, data_type_t *value)
{
    if (stack->top == -1) {
        return ERROR;  
    }
    *value = stack->data[stack->top];  
                                       
    stack->top--;
    return OK;
}

int peek(stack_t *stack, data_type_t *value)
{
    if (stack->top == -1) {
        return ERROR;  
    }
    *value = stack->data[stack->top];  
    return OK;
}