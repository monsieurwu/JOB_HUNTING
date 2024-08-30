#include<stdio.h>
int find_substr(char *s, char *sub);
int main() {

    char str[] = "This is a test string";
    char sub[] = "st";
    int index = find_substr(str, sub);
    if (index == -1)
    {
        printf("Substring not found\n");
    }
    else {
        printf("Substring found at index %d\n", index);
    }
    return 0;
}

int find_substr(char *s, char *sub)
{
    int len_s = 0, len_sub = 0;
    while (s[len_s]!= '\0') len_s++;
    while (sub[len_sub]!= '\0') len_sub++;

    for (int i = 0; i <= len_s - len_sub; i++) {
        int j = 0;
        while (j < len_sub && s[i + j] == sub[j]) j++;
        if (j == len_sub) return i;
    }
    return -1;  // Substring not found in the string


}