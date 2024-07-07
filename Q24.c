#include <stdio.h>

typedef enum 
{
    ��ѧ,
    Ӣ��,
    ����,
    ��ѧ
} CourseType;

typedef struct 
{
    CourseType type;
    int credit;
    float score;
} Course;

void addCourse(Course *courses, int *count) 
{
    Course newCourse;

    printf("������γ����ͣ�0-��ѧ��1-Ӣ�2-����3-��ѧ����");
    int typeInput;
    scanf("%d", &typeInput);

    printf("������ѧ�֣�");
    scanf("%d", &newCourse.credit);

    printf("������ɼ���");
    scanf("%f", &newCourse.score);

    switch (typeInput) 
    {
        case 0:
            newCourse.type = ��ѧ;
            break;
        case 1:
            newCourse.type = Ӣ��;
            break;
        case 2:
            newCourse.type = ����;
            break;
        case 3:
            newCourse.type = ��ѧ;
            break;
        default:
            printf("����Ŀγ��������롣\n");
            return;
    }

    if (*count < 10) 
    {
        courses[*count] = newCourse;
        (*count)++;
    } 
    else 
    {
        printf("�γ������������޷���Ӹ���γ̡�\n");
    }
}

float calculateGPA(Course *courses, int count) 
{
    float totalGPA = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < count; ++i) 
    {
        int credit = courses[i].credit;
        float score = courses[i].score;

        if (score >= 90.0) 
        {
            totalGPA += 4.0 * credit;
        } 
        else if (score >= 80.0) 
        {
            totalGPA += 3.0 * credit;
        } 
        else if (score >= 70.0) 
        {
            totalGPA += 2.0 * credit;
        } 
        else if (score >= 60.0) 
        {
            totalGPA += 1.0 * credit;
        }

        totalCredits += credit;
    }

    float GPA = totalGPA / totalCredits;

    return GPA;
}

int main() {
    int numCourses;

    printf("������γ�������������10�ţ���");
    scanf("%d", &numCourses);


    if (numCourses > 10 || numCourses <= 0) 
    {
        printf("�γ�����������Χ���������\n");
        return -1;
    }

    Course courses[10];
    int count = 0;

    for (int i = 0; i < numCourses; ++i) 
    {
        addCourse(courses, &count);
    }

    float GPA = calculateGPA(courses, count);

    printf("ƽ��ѧ�ּ���Ϊ��%.2f\n", GPA);

    return 0;
}


