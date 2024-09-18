#include<stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int calc(int (*fun)(int, int), int a, int b)
{
    return fun(a, b);
}
int  main() {
    int (*operation)(int, int);
    operation = add;
    printf("%d\n", operation(5, 3));

    operation = subtract;
    printf("%d\n", operation(5, 3));

    printf("5+3=%d\n", calc(add, 5, 3));
    printf("5-3=%d\n", calc(subtract, 5, 3));

    return 0;
}