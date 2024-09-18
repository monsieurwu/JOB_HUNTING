      
#include <stdio.h>
#include "stdlib.h"
// 指针 global_string 本身，是全局变量
// 指针 global_string 指向的 “hello world” 是字符串字面量
char* global_string = "hello world"; /* 代码段，.rodata */
// 全局变量（初始化）
int global_init_array[8] = {1,2,3,4,5,6,7,8}; /* 初始化数据段（.data） */
// 静态全局变量（初始化）
static int static_global_init_array[8] = {1,2,3,4,5,6,7,8}; /* 初始化数据段（.data） */

// 全局变量（未初始化）
int global_uninit_array[8]; /* 未初始化数据段（.bss）会被自动初始化为 0 */
// 静态全局变量（未初始化）
static int static_global_uninit_array[8]; /* 未初始化数据段（.bss）会被自动初始化为 0 */

void function(int para) // 函数参数（栈）
{
    // 局部变量（栈）
    int local_var = 5;

    // 指针 heap_var1 本身，是局部变量（栈）
    // 指针 heap_var1 指向的一段连续空间，是动态分配的内存（堆）
    int *heap_var1 = (int *)malloc(sizeof(int) * 8);
    if (heap_var1 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int *heap_var2 = (int *)malloc(sizeof(int) * 8);
    if (heap_var2 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Address of para: %p\n", (void *)&para);
    printf("Address of local_var: %p\n", (void *)&local_var);
    printf("Address of heap_var1: %p\n", (void *)&heap_var1);
    printf("Address of heap_var2: %p\n", (void *)&heap_var2);
    printf("Address of [heap1]: %p\n", (void *)heap_var1);
    printf("Address of [heap2]: %p\n", (void *)heap_var2);

    // 释放动态分配的内存
    free(heap_var1);
    free(heap_var2);
}

int main(void)
{   
    // 静态局部变量（初始化）
    static int static_local_init_array[8] = {1,2,3,4,5,6,7,8}; /* 初始化数据段（.data） */
    // 静态局部变量（未初始化）
    static int static_local_uninit_array[8]; /* 未初始化数据段（.bss）会被自动初始化为 0 */
 
    printf("system init!\n");
    printf("Address of [hello world]: %p\n", (void *)global_string);
    printf("Address of global_string: %p\n", (void *)&global_string);
    printf("Address of global_init_array: %p\n", (void *)&global_init_array);
    printf("Address of static_global_init_array: %p\n", (void *)&static_global_init_array);
    printf("Address of static_local_init_array: %p\n", (void *)&static_local_init_array);
    printf("Address of global_uninit_array: %p\n", (void *)&global_uninit_array);
    printf("Address of static_global_uninit_array: %p\n", (void *)&static_global_uninit_array);
    printf("Address of static_local_uninit_array: %p\n", (void *)&static_local_uninit_array);
    
    function(10);
    
    return 0;
}
