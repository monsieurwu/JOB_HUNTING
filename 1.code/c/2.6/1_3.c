#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
int i = 1;

int files_count = 0;
int all_line_count = 0;

void print_file_info(struct stat file_stat) {
        printf("文件类型：%s\t", S_ISDIR(file_stat.st_mode) ? "文件夹" : "文件");
        printf("文件大小：%ld bytes\n", file_stat.st_size);

                // 打印文件的时间信息
        printf("最后访问时间：%s", ctime(&file_stat.st_atime));
        printf("最后修改时间：%s", ctime(&file_stat.st_mtime));
        printf("状态改变时间：%s", ctime(&file_stat.st_ctime));
        printf("------------------------------------------------------\n");
}


void line_counter(const char* path) {
    FILE *fp;
    char c;
    int line_count = 0;

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF)
        if (c == '\n')
            line_count++;
    
    line_count++;
    fclose(fp);

    printf("行数：%d\n", line_count);
    all_line_count += line_count;
    printf("------------------------------------------------------\n");
}


//递归遍历文件夹
int traverse_dir(const char* directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char path[1024];
    

    // 打开目录
    dir = opendir(directory);
    if (dir == NULL) {
        printf("无法打开目录\n");
        return -1;
    }

    
    // 遍历目录中的每个文件
    while ((entry = readdir(dir)) != NULL) {
        // 跳过 . 和 ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // 拼接完整路径
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        // 获取文件的状态信息
        if (stat(path, &file_stat) == -1) {
            perror("stat");
            continue;
        }




        

        // 如果是文件夹，递归地调用函数
        if (S_ISDIR(file_stat.st_mode)) {

            traverse_dir(path);
        } else { // 否则，打印文件信息
            printf("%d 文件：%s\t", i++, entry->d_name);
            line_counter(path);
            files_count++;
        }


    }

    
    
        closedir(dir);
        return 0;

}

int main(void)
{
    printf("目录 test 中的文件如下：\n\n");
    traverse_dir("/home/wujw/Downloads/lwip-2.1.3");
    printf("in total, there are %d files including %d lines\n", files_count, all_line_count);
    return 0;
}
