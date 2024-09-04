      
#include <stdio.h>
#include <stdlib.h>

#define BOOK_COUNT 6

struct book {
    char name[32];        //书名
    char version[8];      //版次
    long long ISBN;       //ISBN，13位数字，需要用 long long 类型才能保存
    char writer[64];      //作者
    char press[32];       //出版社
    float price;          //单价
};

void print_book(struct book *b);
struct book* search_book(struct book *b, int n, long long ISBN);
float total_price(struct book *b, int n);
float average_price(struct book *b, int n);

    