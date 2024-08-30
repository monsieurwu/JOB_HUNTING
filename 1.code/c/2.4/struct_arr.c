#include<stdio.h>

int main() {
    typedef struct date {
        int year;
        int month;
        int day;

    } DATE;

    typedef struct stu {
        char name[8];
        int age;
        int exam_num;
        char school[16];
        int score;
        DATE birthday;

    } STUDENT;


    STUDENT stu[5] = {
        {"woowoo", 18, 39, "8 middle school", 548, {1996, 5, 30}},
        {"woowoo", 19, 39, "8 middle school", 548,{1996, 5, 30}},
        {"woowoo", 20, 39, "8 middle school", 548,{1996, 5, 30}},
        {"woowoo", 18, 39, "8 middle school", 548,{1996, 5, 30}},
        {"woowoo", 18, 39, "8 middle school", 548,{1996, 5, 30}}
    };
    int query_no = 0;

    for(;;) {
        printf("input index number, input 0 exit:\n");
        scanf("%d", &query_no);

        if(query_no == 0)
        {
            printf("exit\n");
            break;
        }
        else if(query_no < 0 || query_no >= 5)
        {
            printf("input error, please input again\n");
            continue;
        }
        else
        {
            printf("name: %s\n", stu[query_no-1].name);
            printf("age: %d\n", stu[query_no-1].age);
            printf("exam_num: %d\n", stu[query_no-1].exam_num);
            printf("school: %s\n", stu[query_no-1].school);
            printf("score: %d\n", stu[query_no-1].score);
            printf("birthday: %d-%d-%d\n", stu[query_no-1].birthday.year, stu[query_no-1].birthday.month, stu[query_no-1].birthday.day);
        }


    }


    return 0;
}