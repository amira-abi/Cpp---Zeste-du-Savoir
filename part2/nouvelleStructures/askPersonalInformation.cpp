#include <iostream>

int main(){

    std::vector<std::string> ask {"NOM ?", "PRENOM ?", "AGE ?", "SEXE ?"}
    std::ofstream file {"Cameron.Diaz.csv"};

    std::string input {""};

    for( question : ask) {
        std::cout << question << std::endl;
        std::cin >> input;
        file << std::flush;
    }

    std::cout << "Thos info will be saved in the file Cameron.Diaz.csv" << std::endl;

    return 0;

}