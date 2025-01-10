#include "book_seq_list.h"

int init_book_list(struct book_list *list)
{
    if (list == NULL)
    {
        return ERROR; /* 如果list指针为NULL，则返回错误 */
    }

    list->length = 0; /* 初始化长度为0 */
    return OK;
}
// 打印顺序表中的元素（遍历）
void print_book_list(struct book_list *list)
{
    int i;
    printf("book list:\n");
    for (i = 0; i < list->length; i++) {
        printf("书名：%s, 版次：%s, ISBN：%lld, 作者：%s, 出版社：%s, 单价：%f\n",
            list->data[i].name, list->data[i].version, list->data[i].ISBN, 
            list->data[i].writer, list->data[i].press, list->data[i].price);
    }
    printf("\n");
}
/* 增加元素到顺序表末尾 */
int append_book(struct book_list *list, book_t value)
{
    if (list->length < MAX_SIZE)
    {
        list->data[list->length] = value;
        list->length++;
        return OK;
    }
    else
    {
        printf("Sequential list is full, cannot insert new element.\n");
        return ERROR;
    }
}

/* 在指定位置插入元素
 * 在list 的position下标处，插入新的元素value,list长度加1
 */
int insert_book(struct book_list *list, int position, book_t value)
{
    int i;

    if (list->length >= MAX_SIZE)
    {
        printf("Sequential list is full, cannot insert new element.\n");
        return ERROR;
    }
    if (position < 0 || position > list->length)
    {
        printf("Invalid position.\n");
        return ERROR;
    }

    /* 将要插入位置后的数据元素向后移动一位 */
    for (i = list->length; i > position; i--)
    {
        list->data[i] = list->data[i - 1];
    }

    list->data[position] = value;
    list->length++;
    return OK;
}

/* 删除指定下标的元素 
 * 删除list的position下标处元素，list长度减1
*/
int delete_book(struct book_list *list, int position)
{
    int i;

    if (position < 0 || position >= list->length)
    {
        printf("Invalid position.\n");
        return ERROR;
    }

    /* 将删除位置后继元素前移 */
    for (i = position; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->length--;
    return OK;
}

/* 查找元素 */
int search_book(struct book_list *list, long long ISBN)
{
    int i;

    for (i = 0; i < list->length; i++)
    {
        if (list->data[i].ISBN == ISBN)
        {
            return i; /* 返回元素位置 */
        }
    }
    return ERROR; /* 未找到返回ERROR */
}

/* 更新指定位置的元素 */
int update_book(struct book_list *list, int position, book_t new_value)
{
    if (position < 0 || position >= list->length)
    {
        printf("Invalid position.\n");
        return ERROR;
    }
    list->data[position] = new_value;
    return OK;
}
/* 初始化书籍结构体 */
void init_book(book_t *book, const char *name, const char *version, long long ISBN, 
        const char *writer, const char *press, float price)
{
    /* 赋值各个成员 */
    strcpy(book->name, name);
    strcpy(book->version, version);
    book->ISBN = ISBN;
    strcpy(book->writer, writer);
    strcpy(book->press, press);
    book->price = price;
}

