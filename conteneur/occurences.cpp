#include <algorithm>
#include <iostream>
#include <string>

int main(){

    std::string const phrase { "Exemple that is use on the forum Zeste de Savoir." };
    auto it_prev {std::begin(phrase)};
    auto it_space { std::find(std::begin(phrase), std::end(phrase), ' ')};

    while(it_space!=std::end(phrase)){

        std::string const word ( it_prev, it_space);
        auto const total_e {std::count(std::begin(word), std::end(word), 'e')};

        std::cout << "In the word '" << word << "' , there is  " << total_e << " 'e' minus." << std::endl;
        ++it_space;
        it_prev = it_space; 
        it_space = std::find(it_space, std::end(phrase), ' ');
    }

    std::string const last {it_prev, std::end(phrase)};
    std::cout<< "The last word '" << last << "'contains " << std::count(it_space, std::end(phrase), 'e') << " 'e' minus" << std::endl;
    return 0;
}