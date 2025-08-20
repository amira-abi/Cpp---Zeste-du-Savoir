#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

/*This function will delete the space at the end and the beginning of the string*/
int main(){

    std::string test { "\n\tHello !\n\t" };
    std::cout << "Before modification : " << test << std::endl;
    
    auto non_space {std::find_if_not(std::begin(test), std::end(test), isspace)};
    test.erase(std::begin(test), non_space);

    std::cout << "Deleted spaces at the beginning : " << test << std::endl;

    std::reverse(std::begin(test), std::end(test));

    non_space = { std::find_if_not(std::begin(test), std::end(test), isspace )};
    test.erase(std::begin(test), non_space);

    std::reverse(std::begin(test), std::end(test));

    std::cout << "Deleted spaces at the end : " << test << std::endl;
    return 0;
}