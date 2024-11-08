#include<stdio.h>

int main() {
    int arr[10] = {0};
    int i, n;
    n = sizeof(arr)/sizeof(arr[0]);
    printf("input 10 numbers: ");
    for(i=0; i<n;i++)
    {
        scanf("%d", &arr[i]);

    }


    return 0;
}