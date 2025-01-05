#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Student
{
    struct list_head list;
    unsigned int age;
}Student;

int main(int argc, char **argv)
{
    Student *stuPtr;
    Student student;
    list_head *listPoint;

    INIT_LIST_HEAD(&student.list);

    for( int idx = 0; idx < 6; idx++ )
    {
        stuPtr = (Student *)malloc(sizeof(Student));
        stuPtr->age = idx * 10;
        list_add(&stuPtr->list, &student.list);
    }

    list_for_each(listPoint, &Student.list)
    {
        printf("age - %d\n", ((Student *)listPoint)->age);
    }
    
    return 0;
}