//
// Created by Andreas on 01.11.2020.
//

#ifndef ASSIGNMENT_7_3_STUDENTS_H
#define ASSIGNMENT_7_3_STUDENTS_H


#include <map>

class Students{
public:
    std::string name;
    std::map<std::string, char> Course;

};

void print_students(std::vector<Students> students,const int* count);
std::vector<Students> read_students(std::vector<Students> students,int* count);



#endif //ASSIGNMENT_7_3_STUDENTS_H
