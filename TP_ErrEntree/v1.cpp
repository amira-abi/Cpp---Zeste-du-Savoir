#include <iostream>

int main(){

    std::cout << "Quel mois es-tu né ? ";
    int mois { 0 };
    std::cin >> mois;
    int jour { 0 };

    std::cout << "Quel jour es-tu né ? ";
    while(!(std::cin >> jour) || (jour<1 || jour>31)){  
        if(mois%2==0 && jour==31){
            std::cout << "Il n'y a que 30 jours pendant les mois pairs (sauf fevrier)!" << std::endl;
        }
        std::cout << "Tu n'as pas rentré un entier valide !" << std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    };

    while(!(std::cin >> mois) && (jour<1 || jour>12)){
        std::cout << "Tu n'as pas rentré un entier valide !" << std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    };
    while(!(std::cin >> jour) || mois==2 && (jour<1 || jour>28)){
        std::cout << "Il n'y a QUE 28 jours en fevrier " << std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }
    while(!(std::cin >> jour) ||  (mois%2==0 && (jour<1 || jour>31))){
        std::cout << "Il n'y a que 30 jours pendant les mois pairs (sauf fevrier)!" << std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }



    std::cout << "Tu es né le " << jour << "/" << mois << "." << std::endl;
}