#include <stdio.h>

int main() {
    char str[] = "12345 67.89 Hello";
    int number;
    float decimal;
    char word[10];

    // 从字符串中解析数据
    sscanf(str, "%d %f %s", &number, &decimal, word);

    printf("Parsed integer: %d\n", number);
    printf("Parsed float: %.2f\n", decimal);
    printf("Parsed string: %s\n", word);

    return 0;
}
