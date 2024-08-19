#include <stdio.h>
#include <time.h>

int main() {
    FILE *stream = NULL;
    int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
    int times = 0;
    int ret;
    time_t seconds;
    struct tm* p_time = NULL;

    stream = fopen("3.txt", "a+");
    if (stream == NULL) {
        printf("Error opening file.\n");
        return -1;
    }
    else {
        printf("open successed\n");
    }

    while((ret = fscanf(stream, "# %d-%d-%d %d:%d:%d # %dth write in the file #\n", &year, &month, &day, &hour, &min, &sec, &times)) > 0)
    {
        printf("success fscanf %d words in %d-%d-%d at %d:%d:%d\n", ret, year, month, day, hour, min, sec);
    }

    seconds = time(NULL);
    p_time = localtime(&seconds);

    ret = fprintf(stream, "# %d-%d-%d %d:%d:%d # %dth write in the file #\n", 1900+p_time->tm_hour, 1+p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec, ++times);

    if (ret < 0) {
        printf("Error writing to file.\n");
    } else {
        printf("Write %d words to file.\n", ret);
    }
    fclose(stream);




}