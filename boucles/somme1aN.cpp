#include <iostream>

int main(){
    int n;
    int result {0};

    while(!(std::cin >> n) && n>=0){
        std::cout << "Il me faut un entier POSITIF";
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << " La somme de 1 à " << n << " est : ";
    while(n!=0){
        result+=n;
        n--;
    }
    std::cout<< result; 
    return 0;
}