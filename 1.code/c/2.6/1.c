#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(void)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char path[1024];
    int i = 1;

    // 打开目录
    dir = opendir("/home/wujw/Downloads/test");
    if (dir == NULL) {
        printf("无法打开目录\n");
        return -1;
    }

    printf("目录 /home/wujw/Downloads/test 中的文件如下：\n\n");

    // 遍历目录中的每个文件
    while ((entry = readdir(dir)) != NULL) {
        // 跳过 . 和 ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // 拼接完整路径
        snprintf(path, sizeof(path), "/home/wujw/Downloads/test/%s", entry->d_name);

        // 获取文件的状态信息
        if (stat(path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        printf("%d 名称：%s\n", i++, entry->d_name);
        printf("文件类型：%s\t", S_ISDIR(file_stat.st_mode) ? "文件夹" : "文件");
        printf("文件大小：%ld bytes\n", file_stat.st_size);

                // 打印文件的时间信息
        printf("最后访问时间：%s", ctime(&file_stat.st_atime));
        printf("最后修改时间：%s", ctime(&file_stat.st_mtime));
        printf("状态改变时间：%s", ctime(&file_stat.st_ctime));

    

    
    }

    // 关闭目录
    closedir(dir);

    return 0;
}
