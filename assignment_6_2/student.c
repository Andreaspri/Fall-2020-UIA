//
// Created by Andreas on 20.10.2020.
//

#include <stdio.h>
#include <string.h>

void write_student(student_t *student,int const *count)
{
    printf("Count: %i\n",*count);
    for (int i=0;i < *count;i++)
    {
        printf("Name = %s, Age = %i\n",(student + i)->name,(student + i)->age);
    }
}
int read_student(student_t *student,int *count)
{
    fgets((student + *count)->name,50,stdin);
    (student + *count)->name[strlen((student + *count)->name)-1] = 0;
    if(strcmp((student + *count)->name,"stop") == 0)
        return 1;
    scanf("%i",&(student + *count)->age);
    getchar();
    *count+=1;
    return 0;

}


void oldest_youngest(student_t* student, int const *count)
{
    int young=0;
    int old=0;
    for (int i=0;i<*count;i++){
        if ((student+i)->age<(student+young)->age)
            young=i;
        if ((student+i)->age>(student+old)->age)
            old=i;
    }
    printf("Youngest: %s\n",(student+young)->name);
    printf("Oldest: %s",(student+old)->name);
}