#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
int cp(const char *src, const char *dst) {
    FILE *srcFile, *dstFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // 打开源文件（只读模式）
    srcFile = fopen(src, "rb");
    if (srcFile == NULL) {
        perror("打开源文件失败");
        return -1;
    }

    // 打开目标文件（写模式），如果文件不存在则创建
    dstFile = fopen(dst, "wb");
    if (dstFile == NULL) {
        perror("打开目标文件失败");
        fclose(srcFile);
        return -1;
    }

    // 读取源文件并写入目标文件
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        if (fwrite(buffer, 1, bytesRead, dstFile) != bytesRead) {
            perror("写入目标文件失败");
            fclose(srcFile);
            fclose(dstFile);
            return -1;
        }
    }

    // 关闭文件
    fclose(srcFile);
    fclose(dstFile);

    return 0;
}
int main(int argc, char *argv[])
{
    for(int i=0; i<argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    cp(argv[1], argv[2]);

    return 0;
}