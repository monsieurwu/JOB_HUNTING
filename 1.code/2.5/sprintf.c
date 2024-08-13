#include <stdio.h>

int main() {
    int number = 12345;
    char buffer1[10];
    char buffer2[10];

    // 使用 sprintf 写入 buffer1
    sprintf(buffer1, "%d", number);
    printf("Using sprintf: %s\n", buffer1);

    // 使用 snprintf 写入 buffer2
    snprintf(buffer2, sizeof(buffer2), "%d", number);
    printf("Using snprintf: %s\n", buffer2);

    return 0;
}
