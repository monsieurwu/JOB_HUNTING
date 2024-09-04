#include <stdio.h>
#include <string.h>

int main() {
    char line[] = "root:x:0:0:root:/root:/bin/bash";
    char *token;

    token = strtok(line, ":");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");

    }
    return 0;
}