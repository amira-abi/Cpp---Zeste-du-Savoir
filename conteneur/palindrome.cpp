#include <iostream>
#include <string>
#include <array>
#include <algorithm>


/* This method determines if a string is a palindrome,
 meaning it remains the same when reversed.
*/
int main(){

    std::array<std::string, 5> words {"racecar", "level", "car", "madam", "chocolate"};

    for(auto x : words){
        std::cout << std::boolalpha;
        std::string reverse_word = x;
        std::reverse(std::begin(reverse_word), std::end(reverse_word));
        std::cout << "Est ce que '"<< x << "' est un palindrome ? : " << std::equal(std::begin(x), std::end(x), std::begin(reverse_word), std::end(reverse_word)) << std::endl; 

    }
    return 0;
}