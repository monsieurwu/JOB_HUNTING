#include<stdio.h>

int main() {
    int arr[5] = {5, 1, 7, 9, 33};
    int arr_2[5];
    int i = 0;
    int n;
    n = sizeof(arr) / sizeof(arr[0]);

    for(; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);

    }

    printf("after reverse\n");

    for(int j = 0, i = n; j < n; j++, i--)
    {
        arr_2[j] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("arr_2[%d] = %d\n", i, arr_2[i]);

    }
    

    return 0;
}