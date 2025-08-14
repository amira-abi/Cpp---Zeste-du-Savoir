#include <iostream>
#include <vector>

int main(){

    std::vector<char> alpha {'a', 'b', 'c', 'a', 'd',
    'e', 'f', 'g', 'b', 'h',
    'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'a', 'b'};

    std::vector<char> countedAlpha {};

    for(size_t i = 0; i < std::size(alpha); i++){
        bool isAlphaCounted {false};
        for(auto const c : countedAlpha){
            if(c == alpha[i]){
                isAlphaCounted = true;
                break;
            }
        }

        if(!isAlphaCounted){
            int count {0};
            countedAlpha.push_back(alpha[i]);
            for(size_t j = 0; j < std::size(alpha); j++){
                if(alpha[i]==alpha[j]){
                    count++;
                }
            }
             std::cout << alpha[i] << " : " << count << std::endl;
        }
    }
    return 0;
}
