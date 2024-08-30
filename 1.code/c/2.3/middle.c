#include <stdio.h>


int *find_middle(int *a, int size);
int main(){
	int arr[] = {6, 5, 33, 678, 44, 22};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *mid = find_middle(arr, size);
    printf("middle of the arr is %d\n", *mid);

	return 0;
}

int *find_middle(int *a, int n)
{
    return &a[n/2];


}