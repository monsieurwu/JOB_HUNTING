#include "book_seq_list.h"
int main(void)
{
    struct book_list list;
    book_t book;
    int pos;

    /* 初始化顺序表 */
    if (init_book_list(&list) == ERROR)
    {
        printf("Failed to initialize the sequential list.\n");
        return ERROR;
    }

    /* 使用 init_book 函数初始化并追加书籍 */
    init_book(&book, "C程序设计语言", "第2版", 9787111128069, "Brian W.Kernighan & Dennis M.Ritchie", "机械工业出版社", 22.90);
    append_book(&list, book);

    init_book(&book, "C语言程序设计现代方法", "第2版", 9787115565198, "K.N.King", "人民邮电出版社", 102.50);
    append_book(&list, book);

    printf("After append, ");
    /* 打印图书表 */
    print_book_list(&list);

    /* 在第2个位置插入一个元素 */
    init_book(&book, "C Primer Plus", "第6版", 9787115521637, "Stephen Prata", "人民邮电出版社", 54.00);
    insert_book(&list, 2, book);
    printf("After insert book at index [2], ");
    print_book_list(&list);

    /* 删除第0个位置的元素 */
    delete_book(&list, 0);
    printf("After delete index [0], ");
    print_book_list(&list);

    /* 查找元素的位置 */
    pos = search_book(&list, 9787115565198);
    if (pos != ERROR)
    {
        printf("ISBN 9787115565198 found at position %d\n\n", pos);
    }
    else
    {
        printf("ISBN 9787115565198 not found.\n\n");
    }

    /* 更新第1个位置的元素 */
    init_book(&book, "明解C语言入门篇 ", "第3版", 9787115404824, "柴田望洋", "人民邮电出版社", 44.50);
    update_book(&list, 1, book);
    printf("After update index [1] to 明解C语言入门篇, ");
    print_book_list(&list);

    return 0;
}