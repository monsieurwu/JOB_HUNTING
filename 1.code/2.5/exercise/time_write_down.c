#include<stdio.h>
#include<time.h>

int main(){
    FILE *stream1 = NULL;
    const char *path = "data.txt";
    time_t seconds;
    struct tm *p_time;
    int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
    int times = 0;
    int ret;


    seconds = time(NULL);
    p_time = localtime(&seconds);

    stream1 = fopen(path, "a+");
    if(stream1 == NULL)
    {
        printf("Error opening file path\n");
        return 1;
    }else {
        printf("File path opened successfully.\n");
    }

    while ((ret = fscanf(stream1, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n", &year, &month, &day, &hour, &min, &sec, &times)) > 0)
    {
        printf("成功读到 %d 个字段：%d-%d-%d %d:%d:%d, times:%d\n", ret, year, month, day, hour, min, sec, times);
    }

    ret = fprintf(stream1, "# %d-%d-%d %d:%d:%d # %dth run of the program #\n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec, ++times);
    if (ret > 0)
        printf("成功写入%d个字节\n", ret);
    else
        printf("写入失败\n");









    if(fclose(stream1) == EOF) {
        printf("Error closing file path\n");
        return 1;

    } 


    return 0;
}