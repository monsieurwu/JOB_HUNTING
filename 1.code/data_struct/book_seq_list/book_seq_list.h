#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OK 0          /* 成功 */
#define ERROR -1      /* 失败 */

#define MAX_SIZE 100  /* 定义数组的最大容量 */

typedef struct book {
    char name[32];        /* 书名 */
    char version[8];      /* 版次 */
    long long ISBN;       /* ISBN，13位数字 */
    char writer[64];      /* 作者 */
    char press[32];       /* 出版社 */
    float price;          /* 单价 */
} book_t;

/* 定义顺序表结构体 */
struct book_list {
    book_t  data[MAX_SIZE]; /* 存储数据的数组 */
    int length;                 /* 当前数组的长度 */
};

int init_book_list(struct book_list *list);
void print_book_list(struct book_list *list);
int append_book(struct book_list *list, book_t value);
int insert_book(struct book_list *list, int position, book_t value);
int delete_book(struct book_list *list, int position);
int search_book(struct book_list *list, long long ISBN);
int update_book(struct book_list *list, int position, book_t new_value);
void init_book(book_t *book, const char *name, const char *version, long long ISBN, 
        const char *writer, const char *press, float price);