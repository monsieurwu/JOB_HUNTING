#include <stdio.h>

int main() {
    int year, month, day_of_year;
    int is_leap_year;
    int days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
                      {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}} ;

    printf("Enter year: ");
    scanf("%d", &year); 
    printf("Enter day: ");
    scanf("%d", &day_of_year);

    is_leap_year = (year % 4 == 0 && year % 100!=0) || (year % 400 == 0);

    month = 0;
    while (day_of_year > days[is_leap_year][month]) {
        day_of_year -= days[is_leap_year][month++];
    }
    printf("%d-%02d-%02d\n", year, month + 1, day_of_year);  // Month is 1-indexed.

    return 0;
}

