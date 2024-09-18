#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n = 10;
    int *array;
    int i;
    int *p;

    array = (int *)malloc(sizeof(int) * n);

    if(array == NULL)
    {
        printf("memory alloc fail!\n");
        return -1;
    }

    for(i=0; i<n; i++)
    {
        array[i] = i;
        //printf("array[%d] = %d\n", i, array[i]);
    }
    i = 0;
    for(p = array; p < array+n; p++)
    {
        printf("array[%d] = %d\n", i++, *p);

    }
    free(array);
    array = NULL;
    return 0; 


    
}