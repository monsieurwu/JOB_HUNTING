#include <stdio.h>
#include <stdlib.h>

// swap a&b
void swap(void *a, void *b, size_t size)
{
    size_t i;
    char temp;
    char *p = a;
    char *q = b;
    for (i = 0; i < size; i++) {
        temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

// sort by bubble method
void simple_sort(void *base, size_t nitems, size_t size,
    int(*compare_func)(const void *, const void *))
{
    size_t i, j;
    char *arr = (char*)base;

    for (i = 0; i < nitems - 1; i++) {
        for (j = 0; j < nitems - i - 1; j++) {
            
            if (compare_func(arr + j * size, arr + (j + 1) * size) > 0) {
               // Swap elements using swap function
                swap(arr + j * size, arr + (j + 1) * size, size);
            }
        }
    }
}

// compare int
int compare_int(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

// compare float
int compare_float(const void *a, const void *b)
{
    if (*(float*)a < *(float*)b)
        return -1;
    if (*(float*)a > *(float*)b)
        return 1;
    return 0;
}

// print int
void print_int_array(int *arr, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// print float
void print_float_array(float *arr, size_t size)
{
    size_t i;
    for (i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int int_arr[] = { 42, 16, 23, 7, 89, 2 };
    float float_arr[] = { 4.2, 1.6, 2.3, 0.7, 8.9, 0.2 };
    size_t n;

    n = sizeof(int_arr) / sizeof(int_arr[0]);
    printf("Before sort\n");
    print_int_array(int_arr, n);
    // ���뺯�� compare_int
    simple_sort(int_arr, n, sizeof(int), compare_int);
    printf("After sort\n");
    print_int_array(int_arr, n);

    n = sizeof(float_arr) / sizeof(float_arr[0]);
    printf("Before float\n");
    print_float_array(float_arr, n);
    
    simple_sort(float_arr, n, sizeof(float), compare_float);
    printf("After float\n");
    print_float_array(float_arr, n);

    return 0;
}