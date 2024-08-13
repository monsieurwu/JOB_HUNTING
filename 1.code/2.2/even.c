#include <stdio.h>
#include <stdlib.h>
#define STUDENT_COUNT 5

void calc_scores(int scores[], int scores_count);
int main(){
	int stu_score[STUDENT_COUNT] = {0};
	int i;
	for(i=0; i<STUDENT_COUNT; i++)
	{
		printf("the %d student's score: %d\n", i, stu_score[i]);
	}

	calc_scores(stu_score, STUDENT_COUNT);
	
	printf("\nAfter calculating the scores:\n");
	for(i = 0; i < STUDENT_COUNT; i++)
	{
        printf("the %d student's score: %d\n", i, stu_score[i]);
    }
	return 0;
}

void calc_scores(int scores[], int scores_count)
{
	int i = 0, scores_sum = 0;
	for(i = 0; i < scores_count; i++)
	{
		printf("number %d: ", i+1);
		scanf(" %d", &scores[i]);
		scores_sum += scores[i];
	}

	printf("sum = %d\n", scores_sum);
	printf("average = %.2f\n", (float)scores_sum / scores_count);


}
