#include<stdio.h>

struct Example {
    char x;
    char y;
    int z;
};

int main() {
    unsigned char array[24] = {0};
    array[0] = 1;
    array[1] = 2;
    array[4] = 3;
    array[8] = 4;
    array[9] = 5;
    array[12] = 6;
    array[16] = 7;
    array[17] = 8;
    array[20] = 9;

    struct Example *ptr = (struct Example *)array;
    struct Example *end = ptr + 3;
    printf("ptr: %p, end: %p\n", ptr, end);
    while(ptr < end) {
        /* data */
        printf("ptr: %p\n", ptr);
        printf("x: %d, y: %d, z: %d\n", ptr->x, ptr->y, ptr->z);
        ptr++;
    };
    
    return 0;
}