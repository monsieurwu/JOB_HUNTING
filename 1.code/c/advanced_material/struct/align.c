#include<stdio.h>

struct student {
    char name;
    int exam_num;
    short age;
    
    //char school[123];
};

int main() {
    struct student stu;
    printf("size of stu: %ld\n", sizeof(struct student));
    
    return 0;
}