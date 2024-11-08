      
#include <stdio.h>


void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            

            printf("bubbling i:%d, j:%d: ", i, j);
            print_array(arr, n);
        }
    }
}

int main(void)
{
    int arr[] = { 10, 2, 5, 4, 7, 11, 500 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before sorting: ");
    print_array(arr, n);
    printf("-----------------------------------------\n");
    
    bubble_sort(arr, n);
    
    printf("-----------------------------------------\n");
    printf("after sorting: ");
    print_array(arr, n);

    return 0;
}