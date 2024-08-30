#include<stdio.h>
#include<string.h>

char string1[] = "hello";
char string2[] = "world";
char string3[] = "hello world";

int main() {
    char *pdest;
    pdest = strstr(string3, string2);
    if (pdest!= NULL) {
        printf("String1 found at position: %ld\n", pdest - string3);
    } else {
        printf("String1 not found in string2.\n");
    }
    
    return 0;

}