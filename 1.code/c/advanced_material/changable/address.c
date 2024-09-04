#include <stdarg.h>
#include <stdio.h>

void print_numbers(int count, ...)
{
    int i, value;
    va_list args;
    va_start(args, count);
    printf("参数 %d 个: ", count);
    
    for (i = 0; i < count; i++) {
        // 使用 va_arg 获取参数，并输出其地址和值
        int *arg_address = va_arg(args, int *);  // 使用指针来查看地址
        value = *(int*)(&arg_address);           // 解引用指针获取值
        
        printf("\n参数 %d 的地址: %p, 值: %d", i + 1, (void*)arg_address, value);
    }
    
    printf("\n");
    va_end(args);
}

int main()
{
    print_numbers(2, 3, 5);
    print_numbers(4, 3, 5, 7, 9);
    return 0;
}
