#include<stdio.h>

typedef struct date {
    int year;
    int month;
    int day;
} DATE;

typedef struct stu {
    int age;
    int exam_num;
    int score;
    DATE birthday;

} STUDENT;

STUDENT makestudent(int age, int exam_num, int score, DATE birthday);



void printstudent(STUDENT s)
{
    printf("age: %d, index: %d, score: %d\nbiethday: %d %d %d\n",  s.age, s.exam_num, s.score, s.birthday.year, s.birthday.month, s.birthday.day);

}



int main() {
    STUDENT s;
    DATE d = {1996, 5, 30};
    s = makestudent(18, 201801, 90, d);
    printstudent(s);

    return 0;
}

STUDENT makestudent(int age, int exam_num, int score, DATE birthday)
{
    STUDENT temp;
    temp.age = age;
    temp.exam_num = exam_num;
    temp.score = score;
    temp.birthday = birthday;
    return temp;


}