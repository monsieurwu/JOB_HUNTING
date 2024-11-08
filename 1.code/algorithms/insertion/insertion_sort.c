#include<stdio.h>

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];        
        j = i - 1;            


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;              
        }
        arr[j + 1] = key;           

       
        printf("after inserting card [%d]: ", key);
        print_array(arr, n);
    }
}

int main(void)
{
    int arr[] = { 10, 2, 5, 4, 7, 11, 500 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before sorting: ");
    print_array(arr, n);
    printf("-----------------------------------------\n");
    
    insertion_sort(arr, n);
    
    printf("-----------------------------------------\n");
    printf("after sorting: ");
    print_array(arr, n);

    return 0;
}