#include<stdio.h>
#define SIZE 10
int *find_largest(int a[], int n);
int main()
{
    int arr[SIZE]= {10, 20, 30, 400, 50, 60, 70, 80, 90, 100};
   
   
    int *largest = find_largest(arr, SIZE);
    printf("The largest number is: %d\n", *largest);

    return 0;
}

int *find_largest(int a[], int n)
{
    int *largest = a;
    for(int i=1; i<n; i++)
    {
        if(a[i] > *largest)
            *largest = a[i];
    }
    
   
    return largest;


}