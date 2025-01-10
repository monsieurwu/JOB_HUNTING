#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int total_file = 0;
int total_blank = 0;
int total_code = 0;

struct code_line {
    char* language;
    char* suffix;
    int file;
    int blank;
    int code;
};

#define MAX_LANGUAGE_CNT 10

struct code_line cl[MAX_LANGUAGE_CNT] = {
    {"C", "c", 0, 0, 0},
    {"C++", "cpp", 0, 0, 0},
    {"C/C++ Header", "h", 0, 0, 0},
    {"HTML", "html", 0, 0, 0},
    {"CSS", "css", 0, 0, 0},
    {"JavaScript", "js", 0, 0, 0},
    {"Shell", "sh", 0, 0, 0},
    {"TXT", "txt", 0, 0, 0}
};
int search_suffix(const char* name)
{
    int i;
    const char*p;
    p = strrchr(name, '.');
    
    if(p == NULL)
        return -1;
    if(*(++p) == '\0')
        return -1;
    for(i = 0; i < MAX_LANGUAGE_CNT; i++) {
        if(cl[i].suffix == NULL) {
            continue;
        }
        
        else if(strcmp(p, cl[i].suffix) == 0)

            return i;
    }
    
    return -1;
}
void code_line_print(void)
{
    int i;
     // 打印表头
    printf("-------------------------------------------------\n");
    printf("%-8s\t%8s\t%8s\t%8s\n", "编程语言", "files", "blank", "code");
    printf("-------------------------------------------------\n");

    for(i=0; i<MAX_LANGUAGE_CNT; i++){
        if(cl[i].file > 0)
        {
            printf("%-8s\t%8d\t%8d\t%8d\n", cl[i].language, cl[i].file, cl[i].blank, cl[i].code);
        }
    }
    printf("-------------------------------------------------\n");
    printf("%-8s\t%8d\t%8d\t%8d\n", "总计", total_file, total_blank, total_code);
    printf("-------------------------------------------------\n");
}

int count_file_line(const char* path, int* blank, int* code) 
{
    FILE *fp = NULL;
    char c = 0;
    int n = 0;
    int b = 0;
    int lastc = 0;

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            if(lastc == '\n')
                ++b;
            else
                ++n;
        }
        lastc = c;
    }
    
    if(lastc == '\n')
        ++b;
    else
        ++n;

    *blank = b;
    *code = n;

    fclose(fp);
    return 0;
}


//递归遍历文件夹
int traverse_dir(const char* directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    char filepath[2048] = { 0 };

    int index, blank, code;

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
            
        //printf("directory:%s\tentry->d_name:%s\n", directory, entry->d_name);
        

        // 拼接完整路径
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
        printf("filepath:%s\n", filepath);
        // 获取文件的状态信息
        if (stat(filepath, &file_stat) == -1) {
            perror("stat");
            printf("wujw\n");

            continue;
        }
        printf("wujw222\n");

        // 如果是文件夹，递归地调用函数
        if (S_ISDIR(file_stat.st_mode)) {
            
            traverse_dir(filepath);
        } else { // 否则，打印文件信息
        index = search_suffix(entry->d_name);
        printf("index = %d\n", index);
            if(index >= 0) {

                if(count_file_line(filepath, &blank, &code) == 0) {
                    cl[index].file++;
                    cl[index].blank += blank;
                    cl[index].code += code;

                    total_file++;
                    total_blank += blank;
                    total_code += code;
                }
            } else {
                printf("Unknown file type: %s\n", entry->d_name);
            }
        }
    }
    closedir(dir);
    return 0;

}

int main(void)
{
   
    traverse_dir("/home/wujw/Downloads/lwip-2.1.3");
    traverse_dir("/home/wujw/Downloads/test");
    code_line_print();
    return 0;
}
