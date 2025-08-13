#include <iostream>
#include <vector>

int main(){
    std::cout << "entrer des valeurs : " << std::endl;
    std::vector<int> valeurs {};
    int ajout {0};
    int somme {0};
    int moyenne {0};
    while(true){
        while(!(std::cin >> ajout)){
            std::cout << " Tu dois rentrer un entier valide !" << std::endl;
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        if(ajout<0){
            break;
        }
        valeurs.push_back(ajout);
    }

    for(auto const x : valeurs){
        somme+= x;
    }
    std::cout << " La somme vaut : " << somme << std::endl;
    moyenne = somme/(std::size(valeurs));

    std::cout << " la moyenne du tableau est : " << moyenne << std::endl;
    return 0;
}