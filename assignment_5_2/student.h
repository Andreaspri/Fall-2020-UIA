//
// Created by Andreas on 21.09.2020.
//

#ifndef ASSIGNMENT_5_2_STUDENT_H
#define ASSIGNMENT_5_2_STUDENT_H
typedef struct Student{
    char student_id[50];
    char age[50];
    char name[50];
} student_t;

void read_print(FILE* file,student_t student);
void scan_write(FILE* file1,student_t student);

#endif //ASSIGNMENT_5_2_STUDENT_H
