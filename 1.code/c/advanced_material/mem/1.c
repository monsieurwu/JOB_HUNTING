#include<stdio.h>
#include<string.h>

int main() {
    char src[] = "Hello world";
    char dest[50];

    printf("size of src %d, length of src %d\n", sizeof(src), strlen(src));

    memset(dest, '*', sizeof(dest));
    memcpy(dest, src, sizeof(src));
    printf("dest:%s\n", dest);

    memset(dest, '*', sizeof(dest));
    memcpy(dest, src, strlen(src)+1);
    printf("dest:%s\n", dest);

    memset(dest, '*', sizeof(dest));
    strcpy(dest, src);
    printf("dest:%s\n", dest);
        
    memset(dest, '*', sizeof(dest));
    memcpy(dest, src, strlen(src));
    printf("dest:%s\n", dest);


    memcpy(src, src+1, sizeof(src));
    printf("src:%s\n", src);

    return 0;
}