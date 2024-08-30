#include<stdio.h>

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {

    int month;
    printf("input month:\n");
    scanf(" %d", &month);

    if (month >= January && month <= December) {
        switch (month) {
            case January:
            case March:
            case May:
            case July:
            case August:
            case October:
            case December:
                printf("31 days\n");
                break;

            case February:
                printf("28 or 29 days\n");
                break;

            case April:
            case June:
            case September:
            case November:
                printf("30 days\n");
                break;

            default:
                printf("Invalid month\n");
                break;

        }
    }

    return 0;
}