#include<stdio.h>
#define SIZE 5
void reverse(int a[], int n);
int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    for(int i=0; i<SIZE;i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    reverse(arr, SIZE);
    for(int i=0; i<SIZE;i++)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;


}
void reverse(int a[], int n)
{
    int i=0, j=n-1;
    for(; i<j; i++, j--)
    {
       int temp;
       temp = a[i];
       a[i] = a[j];
       a[j] = temp;
    }

}