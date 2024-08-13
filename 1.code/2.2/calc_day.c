#include <stdio.h>
#include <stdlib.h>



int main(){
	int year, day_of_year, month;
	int i, j;
	int date[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31}};
	printf("input year: ");
	scanf(" %d", &year);
	printf("input day: ");
	scanf(" %d", &day_of_year);
	if((year % 4 == 0)&&(year % 100 != 0)||(year % 400 == 0))
	{
		i = 1;
	}
	else
	{
        i = 0;
    }
	j = 0;
	while(day_of_year > date[i][j])
	{
		j++;
		day_of_year -= date[i][j];

	}
    month = j + 1;
	printf("%d %d %d\n", year, month, day_of_year);
	
	
	return 0;

}

