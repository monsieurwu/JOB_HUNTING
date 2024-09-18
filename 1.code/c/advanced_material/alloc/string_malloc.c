#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    const char *str = "hello world";
    char *new_str;

    new_str = (char *)malloc(strlen(str)+1);
    printf("strlen of str: %d\n", strlen(str));
    if(new_str == NULL)
    {
        printf("memory alloc fail!\n");
        return -1;
    }

    strcpy(new_str, str);
    printf("Original string: %s\n", str);
    printf("New string: %s\n", new_str);
    free(new_str);
    new_str = NULL; // to avoid dangling pointer


    return 0;
}