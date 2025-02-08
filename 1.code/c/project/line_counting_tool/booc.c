#include "book.h"    //包含自定义的头文件，用引号
/**
* 功能：  打印一本书的信息
* 参数    b:图书结构体指针
* 返回值：空
*/
void print_book(struct book *b)
{
    printf("书名：%s, 版次：%s, ISBN：%lld, 作者：%s, 出版社：%s, 单价：%f\n",
        b->name, b->version, b->ISBN, b->writer, b->press, b->price);
}
/**
* 功能：      通过ISBN查找图书信息
* 参数        b:图书结构体数组
*             n:图书结构体数组中的图书数量
*            ISBN:图书编号
* 返回值：    找到了指定的图书，返回找到的图书结构体指针，没找到返回 NULL
*/
struct book* search_book(struct book *b, int n, long long ISBN)
{
    int i;
    for (i = 0; i < n; i++, b++) {
        if (b->ISBN == ISBN)
            return b;
    }
    return NULL;
}
/**
* 功能：      返回图书总价
* 参数        b:图书结构体数组
*             n:图书结构体数组中的图书数量
* 返回值：    图书总价
*/
float total_price(struct book *b, int n)
{
    int i;
    float t = 0.0;
    for (i = 0; i < n; i++, b++) {
        t = t + b->price;
    }
    return t;
}
/**
* 功能：      返回图书平均价
* 参数        b:图书结构体数组
*             n:图书结构体数组中的图书数量
* 返回值：    图书平均价
*/
float average_price(struct book *b, int n)
{
    return total_price(b, n) / n;
}
