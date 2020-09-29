#include <stdio.h>
typedef struct student{
    int id;
    int alder;
    char navnet[50];
} student_t;
int main() {
    student_t student;
    scanf("%i\n", &student.id);
    gets(student.navnet);
    scanf("%i", &student.alder);
    printf("Student id: %i\nName: %s\nAge: %i",student.id,student.navnet,student.alder);}