#include<stdio.h>
#include<stdlib.h>

int main() {

    char *str = NULL;
    int value = 0;
    float fvalue = 0.0;

    str = "-2002";
    value = atoi(str);
    printf("%d\n", value);

    str = "-2002.23";
    value = atof(str);
    printf("%s---->%d\n", str, value);
}