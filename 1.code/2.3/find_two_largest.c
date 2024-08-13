#include<stdio.h>
#define SIZE 5

int find_two_largest(int a[], int n, int *largest, int *second_largest);
int main()
{
    int arr[SIZE] = {533, 3, 56333, 342, 1};
    int largest, second_largest;
    

    find_two_largest(arr, SIZE, &largest, &second_largest);
    printf("largest: %d\tsecond largest: %d\n", largest, second_largest);

    return 0;
}


int find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    *largest = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i] > *largest)
        {
            *second_largest = *largest;
            *largest = a[i];
        }
        else if(a[i] > *second_largest && a[i]!= *largest)
        {
            *second_largest = a[i];
        }
        

    }
    
    return 0;


}