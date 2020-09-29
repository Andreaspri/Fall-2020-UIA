//
// Created by Andreas on 21.09.2020.
//
#include <stdio.h>
#include "student.h"

void read_print(FILE* file,student_t student)
{
    file = fopen("student_read.txt", "r");
    if (file == NULL)
        printf("ERROR! file did not open properly file_read\n");
    fscanf(file,"%[^\n]\n",student.student_id);
    fscanf(file,"%[^\n]\n",student.name);
    fscanf(file,"%[^\n]",student.age);

    printf("Student id: %s\n",student.student_id);
    printf("Name: %s\n",student.name);
    printf("Age: %s\n",student.age);
    fclose(file);
}



void scan_write(FILE* file1,student_t student)
{
    printf("Your student id: ");
    gets(student.student_id);
    printf("Your name: ");
    gets(student.name);
    printf("Your age: ");
    gets(student.age);
    file1 = fopen("student_write.txt","w");
    if (file1 == NULL)
        printf("ERROR! file did not open properly file_write\n");


    fprintf(file1, "%s\n", student.student_id);
    fprintf(file1, "%s\n", student.name);
    fprintf(file1, "%s", student.age);
    fclose(file1);
}








