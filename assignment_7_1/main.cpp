#include <iostream>
#include <cstring>



int main() {

    std::string str1;
    std::string str2;

    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    int sub1 = str1.find(str2);
    int sub2 = str2.find(str1);


    if (str1 != str2) {
        std::cout << "The strings are not equal\n" << std::endl;
        if (sub1 >= 0)
            std::cout << "Last string is substring of first string\n" << std::endl;
        else if (sub2 >= 0)
            std::cout << "First string is substring of last string\n" << std::endl;
        else
            std::cout << "There are no substrings\n" << std::endl;
    }
    else if (str1 == str2)
        std::cout << "The strings are equal\n" << std::endl;
    else
        std::cout << "error" << std::endl;





    return 0;
}
