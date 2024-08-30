#include<stdio.h>
#include<string.h>

char string1[] = "hello";
char string2[] = "world";
char string3[] = "hello world";

int main() {
    int ret = 0;
    char input[80] = {0};

    char buffer[80] = {0};
    ret = sprintf(buffer, "input: hello world output: gggg");
    if(ret>0)
        printf("write in %d: %s\n", ret, buffer);
    else
    {
        printf("Error in writing\n");
        return -1;
    }

    ret = sscanf(buffer, "input: hello world output:%s", input);
    if(ret>0)
    {
        printf("Read %d: %s\n", ret, input);
    }
    else
    {
        printf("Error in reading\n");
        return -1;
    }
    
    return 0;

}