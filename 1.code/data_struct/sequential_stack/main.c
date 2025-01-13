#include "sequential_stack.h"
int main(void)
{
    stack_t stack;
    data_type_t value;

    init_stack(&stack);

    if (is_empty(&stack)) {
        printf("Stack is empyt\n\n");
    }
    else {
        printf("Stack not empyt\n\n");
    }
    
    printf("push [%d] into stack\n", 10);
    push(&stack, 10);
    printf("push [%d] into stack\n", 20);
    push(&stack, 20);
    printf("push [%d] into stack\n", 30);
    push(&stack, 30);
    printf("push [%d] into stack\n", 40);
    push(&stack, 40);

    peek(&stack, &value);
    printf("top value of stack is [%d]\n", value);

    while (!is_empty(&stack)) {
        pop(&stack, &value);
        printf("pop stack [%d]\n", value);
    }

    return 0;
}