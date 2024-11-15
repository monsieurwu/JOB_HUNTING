#include<stdio.h>

void strcpy(char *dest, char *src);


int main() {
    char str1[] = "hello dogecoin\n";
    char str2[] = "";

    strcpy(str2, str1);

    printf("%s", str2);

    return 0;
}

void strcpy(char *dest, char *src) {
    while (*dest++ = *src++);
}