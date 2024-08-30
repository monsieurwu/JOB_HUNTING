#include<stdio.h>
#include<time.h>

int main() {
    time_t seconds;
    seconds = time(NULL);
    printf("Current time: %ld \n", seconds);
    
    struct tm *p_time;
    p_time = localtime(&seconds);

    printf("Current date: %d-%d-%d \n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday);
    printf("Current time: %d:%d:%d \n", p_time->tm_hour, p_time->tm_min, p_time->tm_sec);
    
    
    
    return 0;


}