#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void print_file_info(const char *filepath, struct stat *fileStat);
int traverse_dir(const char *path);

int main() {
    traverse_dir("D:\\woowoowoo\\JOB_HUNDING\\1.code\\2.5"); // 请根据你的实际目录调整路径
    return 0; 
}

int traverse_dir(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char filepath[2048] = { 0 };

    if ((dir = opendir(path)) == NULL) {
        perror("opendir error");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')
            continue;

        sprintf(filepath, "%s/%s", path, entry->d_name);
        if (stat(filepath, &fileStat) == -1) {
            perror("stat error");
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            traverse_dir(filepath);
        } else {
            printf("name: %s\n", filepath);
            print_file_info(filepath, &fileStat);
        }
    }

    closedir(dir);
    return 0;
}

void print_file_info(const char *filepath, struct stat *fileStat) {
    printf("readonly: %s\t", (fileStat->st_mode & S_IWUSR) ? "no" : "yes");
    printf("size: %ld bytes\n", fileStat->st_size);

    struct tm *p_time;
    p_time = localtime(&fileStat->st_ctime);
    printf("creation time: %d-%d-%d %d:%d:%d\n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec);

    p_time = localtime(&fileStat->st_mtime);
    printf("modification time: %d-%d-%d %d:%d:%d\n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec);

    printf("-------------------------\n");
}
