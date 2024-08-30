#include<stdio.h>
#define SIZE 100
int string_len(char *s);
int main() {
    char *arr = NULL;
    printf("Enter a string: ");
    scanf("%s", arr); 
    printf("Length of the string is: %d\n", string_len(arr));
    return 0;


}

int string_len(char *s) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}