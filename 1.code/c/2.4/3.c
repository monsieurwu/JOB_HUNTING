#include <stdio.h>

typedef struct book {
    char name[20];
    int version;
    long long isbn;
    char author[20];
    char publisher[10];
    double price;
} BOOK;

void print_help(void);
void query_book_info(BOOK books[], int size);
void print_all_book_info(BOOK books[], int size);
void print_all_book_price(BOOK books[], int size);
void print_average_price(BOOK books[], int size);



int main() {
    BOOK books[] = {
        {"c cxsjyy", 2, 9787111128069, "BWK DMR","jixie", 22.90},
        {"c fanfa", 2, 9787111128070, "KNK","renmin", 102.50},
        {"c prime plus", 6, 9787111128071, "SP","renmin", 54.00},
        {"c rumen", 3, 9787111128072, "CTWY","renmin", 44.50},
        {"c zhizhen", 1, 9787111128073, "KR","renmin", 49.50},
        {"c zhuanjia", 1, 9787111128074, "PVDL","renmin", 60.00},
        };
    int size = sizeof(books)/sizeof(books[0]);
//    int i = 0;
    
    int x;

    while(1){
    print_help();
    printf("enter command number: ");
    scanf("%d", &x);
    switch (x) {
        case 1:
            query_book_info(books, size);
            break;
        case 2:
            print_all_book_info(books, size);
            break;
        case 3:
            print_all_book_price(books, size);
            break;
        case 4:
            print_average_price(books, size);
            break;
        case 0:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid command number!\n");
            //print_help();
            break;
    }
    }
    return 0;



}

void print_help(void)
{
    printf("\nhelp:\n");
    printf("\t1.search for book information\n");
    printf("\t2.print all books infomation\n");
    printf("\t3.get the price of all books\n");
    printf("\t4.get the average price of all books\n");
    printf("\t0.exit the program\n");

}

void query_book_info(BOOK books[], int size)
{
    long long isbn;
    printf("input ISBN: ");
    scanf("%lld", &isbn);
    for(int i = 0; i < size; i++){
        if(isbn == books[i].isbn) {
            printf("\nname:%s, version:%d, ISBN:%lld, author:%s, publisher:%s, price:%.2f\n", books[i].name, books[i].version, books[i].isbn, books[i].author, books[i].publisher,  books[i].price);
            return;
        } 

    }
    printf("\nBook not found!\n");
}

void print_all_book_info(BOOK books[], int size)
{
    for(int i = 0; i < size; i++){
            printf("\nname:%s, version:%d, ISBN:%lld, author:%s, publisher:%s, price:%.2f\n", books[i].name, books[i].version, books[i].isbn, books[i].author, books[i].publisher,  books[i].price);
    }

}

void print_all_book_price(BOOK books[], int size)
{
    double sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += books[i].price;
    }
    printf("\nThe total price of all books is: %.2f\n", sum);
}

void print_average_price(BOOK books[], int size)
{
    double sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += books[i].price;
    }
    printf("\nThe average price of all books is: %.2f\n", (double)sum/size);
}