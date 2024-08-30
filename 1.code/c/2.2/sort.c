#include <stdio.h>
#define ARR_SIZE 10
int main(){
	int arr[ARR_SIZE];
	int i, j, max, min;
	max = 0;

	for(i=0; i<ARR_SIZE; i++)
	{
		printf("input 10 numbers: ");
		scanf(" %d", &arr[i]);
	}
	puts("");
	for(i=0; i<ARR_SIZE; i++)
	{
		printf("arr[%d] = %d\t", i, arr[i]);
	}
	puts("");
	for(i=0; i<10;i++)
	{
		
		if(max<arr[i])
		{
			max = arr[i];
			j = i;

		}

	}
	printf("max = %d, i = %d\n", max, j);
	min = max;
	for(i=0; i<10;i++)
	{
		
		if(min>arr[i])
		{
			min = arr[i];
			j = i;
		}

	}
	printf("min = %d, i = %d\n", min, j);
	



	return 0;
}

