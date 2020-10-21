//
// Created by Andreas on 20.10.2020.
//

#ifndef INC_6_2_IMPROVMENT_STUDENT_H
#define INC_6_2_IMPROVMENT_STUDENT_H
typedef struct Student
{
    char name[50];
    int age;
} student_t;

void write_student(student_t *student,int const *count);
int read_student(student_t *student,int *count);
void oldest_youngest(student_t *student, int const *count);


#endif //INC_6_2_IMPROVMENT_STUDENT_H
