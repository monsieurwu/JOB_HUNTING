#include<stdio.h>
void print_arr(int arr[], int n);
void bubble_sort(int arr[], int n);

int main() {
    int arr[] = { 1,2,3,44,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("before sorting...\n");
    print_arr(arr, n);
    bubble_sort(arr, n);
    printf("after sorting...\n");
    print_arr(arr, n);



    return 0;
}


void print_arr(int arr[], int n) {


    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n){
    int i, j, temp;
    int flag;
    for(i = 0; i < n-1; i++) {
        flag = 0;
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            printf("bubbling i:%d, j:%d\n ", i, j);
            print_arr(arr, n);


        }
        if(!flag) {
            break;
        }



    }


}