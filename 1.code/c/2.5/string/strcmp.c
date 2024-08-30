#include<stdio.h>
#include<string.h>

char string1[] = "hello";
char string2[] = "world";
char string3[] = "hello world";

int main() {
    int result;
    printf("compare: ");
    result = strcmp(string1, string2);
    if (result > 0) {
        printf("%s is greater than %s\n", string1, string2);
    } else if (result < 0) {
        printf("%s is less than %s\n", string1, string2);
    } else {
        printf("%s is equal to %s\n", string1, string2);
    }
    puts("");
    printf("compare: ");
    result = strcmp(string1, string3);
    if (result > 0) {
        printf("%s is greater than %s\n", string1, string3);
    } else if (result < 0) {
        printf("%s is less than %s\n", string1, string3);
    } else {
        printf("%s is equal to %s\n", string1, string3);
    }
    puts("");
    printf("compare: ");
    result = strncmp(string1, string3, 5);
    if (result > 0) {
        printf("%s is greater than %s\n", string1, string3);
    } else if (result < 0) {
        printf("%s is less than %s\n", string1, string3);
    } else {
        printf("%s is equal to %s\n", string1, string3);
    }

    return 0;

}