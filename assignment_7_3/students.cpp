//
// Created by Andreas on 01.11.2020.
//
#include <vector>
#include <iostream>
#include "students.h"







void print_students(std::vector<Students> students,const int* count)
{
    for (int i = 0; i < *count; i++) {
        for (const auto& stud: students[i].Course) {
            std::cout << students[i].name << " - " << stud.first << " - " << stud.second << std::endl;
        }
    }
}


std::vector<Students> read_students(std::vector<Students> students,int* count)
{
    Students student;

    std::string temp_name;
    std::string temp_course;
    char temp_grade;
    while(true)
    {

        students.push_back(student);
        std::cout << "Name: " << std::endl;
        std::getline(std::cin,temp_name);
        if (temp_name == "stop")
            break;
        students[*count].name = temp_name;
        while(true)
        {
            std::cout << "Course: " << std::endl;
            std::getline(std::cin,temp_course);
            if (temp_course == "stop")
            {
                *count+=1;
                break;
            }
            std::cout << "Grade: " << std::endl;
            std::cin >> temp_grade;
            std::getchar();
            students[*count].Course.insert(std::make_pair(temp_course,temp_grade));
        }
    }
    return students;
}


