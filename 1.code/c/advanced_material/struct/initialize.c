#include <stdio.h>
#include <string.h>
struct student {
    char name[8];
    int age;
    int exam_num;
    char school[123];
};
int main() {
    //1
    struct student stu1 = {"David", 18, 140739, "8 middile school"};
    printf("Name: %s\nAge: %d\nExam number: %d\nSchool: %s\n\n", stu1.name, stu1.age, stu1.exam_num, stu1.school);
    //2
    struct student stu2 = {
        .exam_num = 140740,
        .school = "8 middile school",
        .name = "Alice",
        .age = 19
    };
    printf("Name: %s\nAge: %d\nExam number: %d\nSchool: %s\n\n", stu2.name, stu2.age, stu2.exam_num, stu2.school);
    //3
    struct student stu3 = {"Bob", 22};
    printf("Name: %s\nAge: %d\nExam number: %d\nSchool: %s\n\n", stu3.name, stu3.age, stu3.exam_num, stu3.school);

    //4
    struct student stu4;
    strcpy(stu4.name, "Charlie");
    stu4.age = 17;
    stu4.exam_num = 140741;
    strcpy(stu4.school, "8 middile school");
    printf("Name: %s\nAge: %d\nExam number: %d\nSchool: %s\n\n", stu4.name, stu4.age, stu4.exam_num, stu4.school);

    return 0;
}