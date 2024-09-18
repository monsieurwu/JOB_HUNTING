#include<stdio.h>
typedef int (*operation_t)(int, int);
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}
int main() {
    operation_t operation;
    operation = add;
    printf("Addition result: %d\n", operation(5, 3));
    operation = subtract;
    printf("Subtraction result: %d\n", operation(5, 3));

    return 0;
}