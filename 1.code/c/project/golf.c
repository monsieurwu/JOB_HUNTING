#include<stdio.h>

int main() {
    int round = 1;
    float money = 0.1;
    int input = 0;
    printf("input a round number: ");
    scanf("%d", &input);
    if (input < 1 || input > 1000000) {
        printf("Invalid round number!\n");
        return 0;
    }
    printf("---------------------------------\n");
    for (int i = 1; i <= input; i++) {
        printf("| ");
        printf("Round %d:\t", round);
        printf("%10.2f\t", money);
        printf("|\n"); 
        round++;
        money *= 2;
    }
    printf("---------------------------------\n");


    return 0;
}