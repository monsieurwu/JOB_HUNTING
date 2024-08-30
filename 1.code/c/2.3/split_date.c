#include<stdio.h>
int data[2][12] = {
                    {31,29,31,30,31,30,31,31,30,31,30,31},
                    {31,28,31,30,31,30,31,31,30,31,30,31}};
int split_date(int year, int day_of_year, int *month, int *day);
int main()
{
    int year;
    int day_of_year;
    int month, day;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the day of the year: ");
    scanf("%d", &day_of_year);
    split_date(year, day_of_year, &month, &day);
    printf("The date is %d-%d-%d\n", year, month, day);
    return 0;

}

int split_date(int year, int day_of_year, int *month, int *day)
{
    if(((year%4 ==0)&&(year%100!=0))||((year%400)==0)){
        
            int i = 0;
            while(day_of_year > data[0][i]){
                day_of_year -= data[0][i];
                i++;
            }
            *month = i+1;
            *day = day_of_year;
            
        
    }
    else{
            int i = 0;
            while(day_of_year > data[1][i]){
                day_of_year -= data[1][i];
                i++;
            }
            *month = i+1;
            *day = day_of_year;


    }
    return 0;


}