#include <stdio.h>

typedef enum 
{
    数学,
    英语,
    物理,
    化学
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

    printf("请输入课程类型（0-数学，1-英语，2-物理，3-化学）：");
    int typeInput;
    scanf("%d", &typeInput);

    printf("请输入学分：");
    scanf("%d", &newCourse.credit);

    printf("请输入成绩：");
    scanf("%f", &newCourse.score);

    switch (typeInput) 
    {
        case 0:
            newCourse.type = 数学;
            break;
        case 1:
            newCourse.type = 英语;
            break;
        case 2:
            newCourse.type = 物理;
            break;
        case 3:
            newCourse.type = 化学;
            break;
        default:
            printf("错误的课程类型输入。\n");
            return;
    }

    if (*count < 10) 
    {
        courses[*count] = newCourse;
        (*count)++;
    } 
    else 
    {
        printf("课程数组已满，无法添加更多课程。\n");
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

    printf("请输入课程数量（不超过10门）：");
    scanf("%d", &numCourses);


    if (numCourses > 10 || numCourses <= 0) 
    {
        printf("课程数量超出范围或输入错误。\n");
        return -1;
    }

    Course courses[10];
    int count = 0;

    for (int i = 0; i < numCourses; ++i) 
    {
        addCourse(courses, &count);
    }

    float GPA = calculateGPA(courses, count);

    printf("平均学分绩点为：%.2f\n", GPA);

    return 0;
}


