#include<stdio.h>
#include <stdlib.h>
#include <io.h>


int count_file_line(const char *path);
int traverse_dir(const char* directory);
int main() {
    int total_line = 0; 
    

    // total_line = traverse_dir("D:\\test\\test");

    

    // printf("D:\\test in total: %d\n", total_line);

    total_line = traverse_dir("D:\\test\\lwip-2.1.3");

    

    printf("D:\\test: %d\n", total_line);


    return 0;
}

int traverse_dir(const char* directory){  
    struct _finddata_t c_file;
    intptr_t hFile;
    int count = 0;
    int count_alone;
 

    char allfile[1024] = { 0 };
    char filepath[2048] = { 0 };

    sprintf(allfile, "%s\\*", directory);

    // 用通配符 * 获取全部文件信息，返回全部文件组的查找句柄
    if ((hFile = _findfirst(allfile, &c_file)) == -1) {
        printf("_findfirst error\n");
        return -1;
    }

    do {
        count_alone = 0;
        //如果文件名是 . 或 .. ，则不处理
        if (c_file.name[0] == '.')
            continue;

        sprintf(filepath, "%s\\%s", directory, c_file.name);

        //如果是目录，则递归调用
        if (c_file.attrib & _A_SUBDIR) {
           count += traverse_dir(filepath);
        } else {//如果是文件，则打印文件信息
            
            count_alone += count_file_line(filepath);
            count = count + count_alone;
            printf("name: %s include %d lines\n", filepath, count_alone);

            
        }
    } while (_findnext(hFile, &c_file) == 0);//获取下一个文件信息
    
    //关闭查找句柄
    _findclose(hFile);
    return count;

}

int count_file_line(const char *path)
{
    FILE *stream = NULL;
    char c;
    int n = 0, prev_line;
    
    if((stream = fopen(path, "r")) == NULL)
    {
        printf("error occured\n");
        return -1;
    }
    

    while((c = fgetc(stream)) != EOF)
    {
        if(c == '\n')
            n++;
        prev_line = c;
        //putchar(c);

    }
    n++;

    if(fclose(stream) == EOF)
    {
        printf("error occured in close");
        return -1;
    }
    return n;
}
