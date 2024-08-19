#include<stdio.h>
#include<time.h>

int main() {
    FILE *stream = NULL;
    int ret;
    int year = 0, month = 0, day = 0;
    int hour = 0, min = 0, sec = 0;
    int times = 0;
    time_t seconds;
    struct tm *p_time = NULL;

    if((stream = fopen("2.txt", "a+")) == NULL)
    {
        printf("open failed\n");
        return -1;
    }
    else {
        printf("open successed\n");
    }


    while((ret = fscanf(stream, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n", &year, &month, &day, &hour, &min, &sec, &times)) > 0)
    {
        printf("成功读到 %d 个字段：%d-%d-%d %d:%d:%d, times:%d\n", ret, year, month, day, hour, min, sec, times);
    }
    
    seconds = time(NULL);
    p_time = localtime(&seconds);

    ret = fprintf(stream, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n", 1900+p_time->tm_year, 1+p_time->tm_mon, p_time->tm_mday, p_time->tm_hour,  p_time->tm_min, p_time->tm_sec, ++times);
    if(ret>0)
    {
        printf("fprintf 成功\n");
    }
    else {
        printf("fprintf 失败\n");
    }



    return 0;
}