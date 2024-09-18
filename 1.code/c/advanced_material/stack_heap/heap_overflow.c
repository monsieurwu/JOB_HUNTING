#include<stdio.h>
#include<stdlib.h>
void test_max_heap_size(int times)
{
    char *big_heap = (char *)malloc(1*1024*1024);
    times++;
    printf("run %d times\n", times);
    if(big_heap == NULL) {
        printf("no more memory!\n");
        return;
    }
    test_max_heap_size(times);

}
int main() {
    printf("system init\n");
    test_max_heap_size(0);

    return 0;
}