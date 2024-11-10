#include <stdio.h>

int main() {
    int c, i;
    int n_digit[10] = {0};
    int n_space = 0, n_newline = 0, n_other = 0;


    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ++n_digit[c - '0'];
        else if (c == ' ')
            n_space++;
        else if (c == '\n')
            n_newline++;
        else
            n_other++;
    }
    for(i = 0; i < 10; i++)
    {
        printf("Number %d: %d times\n", i, n_digit[i]);
    }
    printf("space times: %d\n", n_space);
    printf("newline times: %d\n", n_newline);
    printf("other times: %d\n", n_other);
    
    return 0;
}