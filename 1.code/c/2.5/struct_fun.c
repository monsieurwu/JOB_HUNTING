#include<stdio.h>

typedef struct stu {
    char name[8];
    int age;
    int exam_num;
    char school[30];
    int score;
} STUDENT;

STUDENT wanger = {"woowoo", 18, 39, "number 8 middle school", 548};

void printstudent(STUDENT s)
{
    printf("school: %s, age: %d, index: %d, score: %d\n", s.school,  s.age, s.exam_num, s.score);

}

void setage(STUDENT *s)
{
    s->age = 28;

}

int main() {
    printf("before modify\t");
    printstudent(wanger);
    setage(&wanger);
    printf("\nafter modify\t");
    printstudent(wanger);


    return 0;
}