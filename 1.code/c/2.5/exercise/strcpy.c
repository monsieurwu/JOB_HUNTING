#include<stdio.h>

void strcpy1(char *str1, char *str2);
int main(){

    char str1[10] = {0};
    char str2[] = "Hello";

    strcpy1(str1, str2);
    printf("str1: %s\n", str1);
    
    return 0;
}

void strcpy1(char *str1, char *str2)
{
    while(*str2!= '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';  // append null terminator to the copied string
}