#include <stdio.h>
#include <time.h>

int main() {
    FILE *stream = NULL;
    int year = 0, month =0, day = 0, hour =0, min = 0, sec = 0;
    int times = 0;
    int ret;
    time_t seconds;
    struct tm *p_time =NULL;

    if((stream = fopen("data.txt", "a+")) == NULL){
        printf("error open\n");
        return -1;
    }
    else {
        printf("open successed\n");
    }

    while((ret = fscanf(stream, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n", &year, &month, &day, &hour, &min, &sec, &times)) > 0)
    {
        printf("match successed. %d-%d-%d %d:%d:%d # %dth\n", year, month, day, hour, min, sec, times);
    }

    seconds = time(NULL);
    p_time = localtime(&seconds);

    ret = fprintf(stream, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec, ++times);

    if (ret > 0)
    {
        printf("fprintf successed\n");
    }
    else {
        printf("fprintf failed\n");
    }

    if(fclose(stream) == EOF)
    {
        printf("close failed");
        return -1;
    }

    

    





    return 0;
}