#include <iostream>

int main(){

    int a;
    int b;

    std::cout << " Premier nombre : ";
    while(!(std::cin >> a)){
        std::cout << "tu dois rentrer un entier : ";
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }
    std::cout << " Deuxieme nombre : ";
    while(!(std::cin >> b)){
        std::cout << "tu dois rentrer un entier : ";
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }

    int premier_nombre {a};
    int deuxieme_nombre {b};
    int r {a%b};

    while(r!=0){
        a=b;
        b=r;
        r = a%b;
    }
    std::cout << "Le PGCD de " << premier_nombre << " et " << deuxieme_nombre << " est : " << abs(b);
    return 0;
}