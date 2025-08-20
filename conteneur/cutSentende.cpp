#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/**
 * Splits a string into words based on a given delimiter character.
 * This is similar to the split() function available in languages like Python or C#.
 */
int main(){

    std::string sentence {"Hello, this is a sentence."};
    std::vector<std::string> wordsList {};
    char const space { ' ' };

    auto begin = std::begin(sentence);
    auto end = std::end(sentence);
    auto it_space {std::find(std::begin(sentence), std::end(sentence), space)};

    while(it_space!=end){
        std::string word {begin, begin + std::distance(begin, it_space)};
        wordsList.push_back(word);

        begin = it_space + 1;
        it_space = {std::find(begin, end, space )};
    }

    std::string word {begin, begin + std::distance(begin, it_space)};
    wordsList.push_back(word);    

    for(auto x : wordsList){
        std::cout << x << std::endl;
    }

    return 0;
}