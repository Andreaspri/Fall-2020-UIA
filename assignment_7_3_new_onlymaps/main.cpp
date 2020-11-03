#include <iostream>
#include <map>


int main() {
std::map<std::string, std::map<std::string,char>> Students;
std::string temp_name;
std::string temp_course;
char temp_grade;

while (true)
{
    std::cout << "Name: " << std::endl;
    std::getline(std::cin,temp_name);
    if (temp_name == "stop")
        break;
    while (true)
    {
        std::cout << "Course: " << std::endl;
        std::getline(std::cin,temp_course);
        if (temp_course == "stop")
            break;
        std::cout << "Grade: " << std::endl;
        std::cin >> temp_grade;
        std::getchar();
        Students[temp_name][temp_course] = temp_grade;
    }
}
    for (auto & name : Students) {
        for (auto & course_grade : name.second)
        {
            std::cout << name.first << " - " << course_grade.first << " - " << course_grade.second << std::endl;
        }
    }
    return 0;
}
