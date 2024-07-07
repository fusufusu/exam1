#include <stdio.h>

typedef struct {
    char name[50];
    int id;
    float grade;
} Student;

void show(Student *students, int num) 
{
    for (int i = 0; i < num; ++i) 
    {
        printf("����: %s\n", students[i].name);
        printf("ѧ��: %d\n", students[i].id);
        printf("�ɼ�: %.2f\n", students[i].grade);
        printf("\n");
    }
}

int main() 
{
    Student students[] = 
    {
        {"������", 001, 59},
        {"����", 002, 61},
    };

    int num = sizeof(students) / sizeof(students[0]);

    show(students, num);

    return 0;
}
