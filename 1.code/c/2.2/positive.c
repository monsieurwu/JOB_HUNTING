#include <stdio.h>
#include <stdlib.h>
#define STUDENT_COUNT 5

void calc_scores(int scores[], int scores_count);
int main(){
	int num[10] = {0};
	int i;
	printf("Enter 10 integers: ");
	for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
	calc_scores(num, 10);

	return 0;
}

void calc_scores(int scores[], int scores_count) {
	int pos = 0;
	for(int i =0; i < scores_count; i++)
	{
		if(scores[i]>0)
		{
            pos++;
		}
	}
	printf("sum of positive number = %d\n", pos);
}
