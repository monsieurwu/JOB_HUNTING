#include <stdio.h>
int max_in_array(int *array, int num) {
    int max = 0;
    for(int i = 0; i < num; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }

    return max;
}
int main(int argc, int **argv) {
    int num[10];
    int n = 0;
    int max_num = 0;
    printf("input 10 number\n");

    n = sizeof(num)/sizeof(num[0]);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    max_num = max_in_array(num, n);
    printf("max number is %d\n", max_num);

    return 0;
}