#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char *path = NULL;
    int path_len = 0;
    struct stat sb;
    struct tm *p_time;
    
    if(argc != 2) {
        printf("method:./file_info <file> or directory\n");
        return -1;
    }

    path = argv[1];
    path_len = strlen(path);
    if(path[path_len-1] == '/') {
        path[path_len-1] = '\0';
    }

    if(stat(path, &sb) == 0) {
        if(S_ISDIR(sb.st_mode)) {
            printf("%s is a directory\n", path);
        } else if(S_ISREG(sb.st_mode)) {
            printf("%s is a file\n", path);
        }

        p_time = localtime(&sb.st_mtime);
        printf("modified time:%d-%d-%d %d:%d:%d\n", 1900+p_time->tm_year, 1+p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec);

        printf("size of the file: %ld bytes\n", sb.st_size);
    } else {
        perror("stat");

    }




    return 0;
}