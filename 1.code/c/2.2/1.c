#include <stdio.h>
void reverse_array(int *array, int num) {
    int temp = 0;
    for (int i = 0; i < num / 2; i++) {
        temp = array[i];
        array[i] = array[num - i - 1];
        array[num - i - 1] = temp;
/**  
 *       temp = *(array+i);
 *       *(array+i) = *(array+num-i-1);
 *       *(array+num-i-1) = temp;
*/
    }

}
int main() {
    int arr[] = {5, 1, 7, 9, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for(; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    reverse_array(&arr, n);
    printf("After reverse\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}