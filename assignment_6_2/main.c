#include "student.h"
#include "student.c"
#include <stdlib.h>
#include <stdio.h>


int main() {
    student_t* student = (student_t*) malloc(sizeof(student_t));
    int temp=0;
    int status=0;
    int *count = &temp;
    while (status == 0)
    {
        student = (student_t*) realloc(student,sizeof(student_t)*(*count+1));
        status = read_student(student,count);
    }
    if (*count == 0)
        printf("No students were given");
    else
    {
        write_student(student, count);
        oldest_youngest(student, count);
        free(student);
    }
    return 0;
}