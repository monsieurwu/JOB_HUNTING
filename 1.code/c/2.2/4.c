#include <stdio.h>
int check_positive_num(int *array, int array_size) {
    int count = 0;
    for (int i = 0; i < array_size; i++) {
        if (array[i] > 0) {
            count++;
        }
    }
    return count;

}
int main() {
    int num = 0;
    int arr[] = {-1, 0, -3, 34, 55, -3, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    num = check_positive_num(arr, arr_size);
    printf("Number of positive numbers: %d\n", num);

    return 0;
}