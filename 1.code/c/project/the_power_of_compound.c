#include<stdio.h>

int main() {
    float monthly_money;
    float interests;
    int month;
    float sum = 0;
    printf("---------------------------------\n");
    printf("monthly invest money: ");
    scanf("%f", &monthly_money);
    printf("annual interests: ");
    scanf("%f", &interests);
    interests = interests/12;
    printf("save for how many months: ");
    scanf("%d", &month);
    for(int i = 1; i <= month; i++) {
        
        sum =(monthly_money+sum) * (1+interests);
        
        
        
    }
    printf("Total after %d months: €%.2f\n", month, sum);
    printf("convert to Yuan: ¥%.2f\n", sum*8);
    printf("---------------------------------\n");



    return 0;
}