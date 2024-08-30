#include <stdio.h>
#define ARR_SIZE 5
int main(){
	int arr[ARR_SIZE] = {5, 1, 7, 9, 33};
	int i, temp;
	for(i=0; i<ARR_SIZE; i++)
	{
		printf("arr[%d] = %d\t", i, arr[i]);

	}
	puts("");
	for(i=0; i<(ARR_SIZE-1)/2; i++)
	{
		temp = arr[i];
		arr[i] = arr[ARR_SIZE-1-i];
		arr[ARR_SIZE-1-i] = temp;
	}	
	for(i=0; i<ARR_SIZE; i++)
	{
		printf("arr[%d] = %d\t", i, arr[i]);

	}
	puts("");



	return 0;
}

