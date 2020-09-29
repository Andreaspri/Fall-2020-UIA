#include <stdio.h>
#include "student.h"
#include "student.c"


FILE * file1;
FILE * file;
int main() {
    student_t student;
    int input;
    while(1) {
        printf("Type 1 to read from file and print\n");
        printf("Type 2 to take input and write to file\n");
        printf("Type 3 to exit\n");
        scanf("%i",&input);
        getchar();
        if (input==1) {
            read_print(file, student);
            break;
        }
        else if(input==2) {
            scan_write(file1, student);
            break;
        }
        else
            break;
    }
    return 0;
}





