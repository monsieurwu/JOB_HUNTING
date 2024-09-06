#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

//文件总数
int total_file = 0;
//空行总数
int total_blank;
//代码行总数
int total_code;

struct code_line {
    char* language; //编程语言名称
    char* suffix;   //编程语言对应的文件后缀名
    int file;       //文件数
    int blank;      //空行数
    int code;       //代码行数
};
//支持的编程语言总数
#define MAX_LANGUAGE_CNT 10
//结构体数组，是全局    变量
struct code_line cl[MAX_LANGUAGE_CNT] = {
    { "C", "c", 0, 0, 0 },
    { "C++", "cpp", 0, 0, 0 },
    { "C/C++ Header", "h", 0, 0, 0 },
    { "Html", "html", 0, 0, 0 },
    { "CSS", "css", 0, 0, 0 },
    { "Javascript", "js", 0, 0, 0 },
    { "Shell", "sh", 0, 0, 0 },
    { "TXT", "txt", 0, 0, 0 }
};
//打印统计结果
void code_line_print(void)
{
    int i;

    printf("-------------------------------------------------------------------\n");
    printf("%-8s%8s\t%8s\t%8s\n", "programming language", "files", "blank", "code");
    printf("-------------------------------------------------------------------\n");

    for (i = 0; i < MAX_LANGUAGE_CNT; i++) {
        //如果包含对应编程语言的文件
        if (cl[i].file > 0)
        {
            printf("%-8s\t%8d\t%8d\t%8d\n", cl[i].language, cl[i].file, cl[i].blank, cl[i].code);
        }
    }

    printf("-------------------------------------------------------------------\n");
    printf("%-8s\t%8d\t%8d\t%8d\n", "in total", total_file, total_blank, total_code);
    printf("-------------------------------------------------------------------\n");
}
/*
 * 功能：查找文件名是否在全局结构体数组中
 * 参数：name：文件名
 * 返回值：>=0：结构体数组的下标
 *         -1：失败或未找到
*/
int search_suffix(const char* name)
{
    int i;
    const char *p;
    //在文件名中从右到左搜索字符 .
    p = strrchr(name, '.');

    if (p == NULL)
        return -1;

    // . 后面的字符串是后缀名，如果一个文件没有后缀名，则不处理
    if (*(++p) == '\0')
        return -1;
    //遍历找到后缀名对应的结构体数组的下标
    for (i = 0; i < MAX_LANGUAGE_CNT; i++) {
        if (cl[i].suffix != NULL && strcmp(p, cl[i].suffix) == 0)
        {
            return i;
        }
    }

    return -1;
}
/*
 * 功能：统计某个文件的空行数、代码行数
 * 参数：path：文件路径，传入参数
 *      blank：空行数量，传出参数
 *       code：代码行数量，传出参数
 *  返回值： 0：成功
 *         -1：失败
*/
int count_file_line(const char* path, int* blank, int* code)
{
    FILE *f = NULL;
    //当前读取的字符；上次读取的字符；上上次读取的字符
    int c = 0, lastc = 0, second_lastc = 0;
    int n = 0;//代码行数
    int b = 0;//空行数

    if ((f = fopen(path, "r")) == NULL) {
        printf("%s 打开失败\n", path);
        return -1;
    }

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            // windows格式文件，换行符是 \r\n
            if (lastc == '\r') {
                // second_lastc 为 0，表示第一行就是空行
                // second_lastc 为 \n，表示当前读到字符及其前面2个字符，是： \n\r\n，这表示一个空行
                if (second_lastc == 0 || second_lastc == '\n')
                    ++b;
                else
                    ++n;
            } 
            // Linux格式文件，换行符是 \n
            else {
                if (lastc == '\n')
                    ++b;
                else
                    ++n;
            }
        }
        second_lastc = lastc;
        lastc = c;
    }

    if (lastc == '\n')
        ++b;    //最后一个字符如果是换行，则最后一行就是空行
    else
        ++n;    //否则，最后一行就包含内容

    *blank = b;
    *code = n;

    fclose(f);

    return 0;
}

void count_line_by_suffix(const char* file_path)
{
    int index, blank, code;
    
    //如果是需要统计的后缀名文件
    if ((index = search_suffix(file_path)) >= 0) {
        //统计空行和代码行数量
        if (count_file_line(file_path, &blank, &code) == 0) {
            //printf("%s: %d, %d\n", file_path, blank, code);
            cl[index].file++;
            cl[index].blank += blank;
            cl[index].code += code;

            total_file++;
            total_blank += blank;
            total_code += code;
        }
    }
}

//遍历目录中的全部内容，传入不以 / 结尾的目录路径
int traverse_dir(const char* dir_path)
{
    DIR *dirp;
    struct dirent *entry;
    char filepath[2048] = { 0 };   

    // 打开目录 test
    dirp = opendir(dir_path);
    if (dirp == NULL) {
        printf("opendir error\n");
        return -1;
    }

    // 读取目录项
    while ((entry = readdir(dirp)) != NULL) {
        // 过滤掉当前目录. 和 父目录..
        if (entry->d_name[0] == '.') {
            continue;
        }
        sprintf(filepath, "%s/%s", dir_path, entry->d_name);
        if (entry->d_type == DT_DIR){
            traverse_dir(filepath);
        } else if (entry->d_type == DT_REG){
            count_line_by_suffix(filepath);
        }
    }

    // 关闭目录
    closedir(dirp);

    return 0;
}

int code_line(const char* path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        printf("stat error\n");
        return -1;
    }
    //普通文件直接统计
    if (S_ISREG(sb.st_mode)) {
        count_line_by_suffix(path);
    } else if (S_ISDIR(sb.st_mode)){
        traverse_dir(path);
    } else {
        // do nothing
    }
}

int main(int argc, char *argv[])
{
    char* path = NULL;
    int path_len = 0;

    if(argc != 2) {
        printf("用法：./cl <file> or <directory>\n");
        return -1;
    }

    path = argv[1];
    path_len = strlen(path);
    //统一路径，如果结尾是 / 则将其去掉
    if (path[path_len - 1] == '/') {
        path[path_len - 1] = '\0';
    }
    //printf("test path:%s\n", path);

    code_line(path);
    code_line_print();
    return 0;
}