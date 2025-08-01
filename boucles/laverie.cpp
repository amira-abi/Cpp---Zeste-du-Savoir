#include <iostream>

int main(){

    int weight;
    std::cout << "Quel est le poids du linge que tu dois laver ?";

    while(!(std::cin >> weight) || (weight<1)){
        std::cout << "la valeur n'est pas bonne, recommence... ";
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }
    if(weight<5){
        std::cout << "Il faut les mettre dans machine de 5 kg" << std::endl;
    }else if(weight<10){
        std::cout << "Il faut les mettre dans machine de 10 kg" << std::endl;
    }else{
        int nb_machine_10 {0};
        int nb_machine_5 {0};

        while(weight>5){
            weight-=10;
            nb_machine_10++;
        }
        if(weight>0){
            nb_machine_5++;
        }
        std::cout << "Tu dois faire " << nb_machine_10 << " machines de 10 kg et "<< nb_machine_5 <<" de 5 kg.";

    }
    return 0;
}