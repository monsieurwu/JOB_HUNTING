#include<stdio.h>

enum Weekday {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main() {
    enum Weekday today = WEDNESDAY;

    switch (today){
        case MONDAY:
            printf("Today is MONDAY.\n");
            break;
        case TUESDAY:
            printf("Today is TUESDAY.\n");
            break;
        case WEDNESDAY:
            printf("Today is WEDNESDAY.\n");
            break;
        case THURSDAY:
            printf("Today is THURSDAY.\n");
            break;
        case FRIDAY:
            printf("Today is FRIDAY.\n");
            break;
        default:
            printf("Invalid day of the week.\n");
            

    }


    return 0;
}