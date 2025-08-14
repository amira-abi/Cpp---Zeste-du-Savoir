#include <iostream>
#include <vector>

int main(){
    std::cout << "Input values : " << std::endl;
    std::vector<int> valeurs {};
    int ajout {0};
    int somme {0};
    int moyenne {0};
    while(true){
        while(!(std::cin >> ajout)){
            std::cout << " You have to give a valid integer !" << std::endl;
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        if(ajout<0){
            break;
        }
        valeurs.push_back(ajout);
    }
    if(!std::empty(valeurs)){
        for(auto const x : valeurs){
        somme+= x;
        }
        std::cout << " The sum worth : " << somme << std::endl;
        moyenne = somme/(std::size(valeurs));

        std::cout << " The average of the array elements is  : " << moyenne << std::endl;
    }else{
        std::cout << "The array is empty , I can't calculate the average." << std::endl;
    }
    
    return 0;
}