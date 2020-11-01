
#include <vector>
#include "students.h"
#include "students.cpp"




int main()
{
    int null=0;
    int* count = &null;

    std::vector<Students> students;

    students = read_students(students,count);

    print_students(students,count);



    return 0;
}

