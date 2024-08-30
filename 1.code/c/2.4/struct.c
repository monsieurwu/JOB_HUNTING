#include<stdio.h>

int main() {
    typedef struct stu {
        char name[8];
        int age;
        int exam_num;
        char school[16];
        int score;
    } STUDENT;

    STUDENT stu1 = {"woowoo", 18, 39, "8 middle school", 548};

    printf("name: %s, age: %d, exam number: %d, school: %s, score: %d\n", stu1.name, stu1.age, stu1.exam_num, stu1.school, stu1.score);
    stu1.age = 28;
    printf("name: %s, age: %d, exam number: %d, school: %s, score: %d\n", stu1.name, stu1.age, stu1.exam_num, stu1.school, stu1.score);

    return 0;
}