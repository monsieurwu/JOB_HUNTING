#include<stdio.h>
#include<time.h>

int main() {
    time_t seconds;
    seconds = time(NULL);
    printf("Current time: %ld \n", seconds);
    seconds = 0;
    time(&seconds);
    printf("Current time: %ld \n", seconds);


}