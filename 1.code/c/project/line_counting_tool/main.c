#include "book.h"    //包含自定义的头文件，用引号

int main(void)
{
    struct book books[BOOK_COUNT] = {
        { "C程序设计语言", "第2版", 9787111128069, "Brian W.Kernighan & Dennis M.Ritchie", "机械工业出版社", 22.90 },
        { "C语言程序设计现代方法", "第2版", 9787115565198, "K.N.King", "人民邮电出版社", 102.50 },
        { "C Primer Plus", "第6版", 9787115521637, "Stephen Prata", "人民邮电出版社", 54.00 },
        { "明解C语言入门篇 ", "第3版", 9787115404824, "柴田望洋", "人民邮电出版社", 44.50 },
        { "C和指针", "第1版", 9787115522689, "Kenneth Reek", "人民邮电出版社", 49.50 },
        { "C专家编程", "第1版", 9787115521323, "Peter Van Der Linden", "人民邮电出版社", 60.00 }
    };

    struct book *b;
    int i, cmd = 0;
    long long ISBN;

    for (;;) {//死循环
        printf("\n支持命令："
            "\n\t1：查询图书信息"
            "\n\t2：打印全部图书信息"
            "\n\t3：计算全部图书总价"
            "\n\t4：计算全部图书平均价"
            "\n\t0：退出程序"
            "\n请输入命令编号：");

        scanf("%d", &cmd);

        if (cmd == 0) {
            printf("程序退出\n");
            break;
        }
        switch (cmd) {
        case 1:
            printf("请输入ISBN号码：\n");
            scanf("%lld", &ISBN);

            b = search_book(books, BOOK_COUNT, ISBN);
            if (b != NULL) {
                printf("找到了！\n");
                print_book(b);
            }
            break;
        case 2:
            b = books;
            for (i = 0; i < BOOK_COUNT; i++, b++) {
                print_book(b);
            }
            break;
        case 3:
            printf("全部图书总价为：%f\n", total_price(books, BOOK_COUNT));
            break;
        case 4:
            printf("全部图书平均价为：%f\n", average_price(books, BOOK_COUNT));
            break;
        default:
            printf("命令无效\n");
            break;
        }
    }
    return 0;
}
