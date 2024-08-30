#include<stdio.h>
#include<string.h>

char string1[] = {"hello--"};
char string2[] = {"world--"};
char string3[] = {"hello world--"};
int main() {
    char string[80] = {0};
    strcpy(string, string1);
    printf("%s\n", string);
    strncpy(string, string2, strlen(string2));
    printf("%s\n", string);

    strcat(string, string3);
    printf("%s\n", string);
   

    return 0;
}