#include <iostream>
#include <array>

std::array<int,9> ATM(int money){
    std::array<int,9> nbCash;
    std::array<int,9> cash {500,200,100,50,20,10,5,2,1};

    nbCash.fill(0);
    int i = 0;
    for( int x : cash){
        while(money>=x){
            money = money - x;
            nbCash[i]++;
        }
        i++;
    }

    return nbCash;
}

int main(){
    std::array<int,9> cash {500,200,100,50,20,10,5,2,1};
    int money {0};

    std::cout << "Please enter the amount you would like to withdraw : "<< std::endl;
    while(!(std::cin >> money)|| money<1){
        std::cout << "The value is wrong, try again..."<< std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }

    std::cout << " You want to withdraw " << money << "euros. This operation could take a few minutes..." << std::endl;
    std::array<int, 9> nbCash {ATM(money)};

    for(int i = 0; i<9; i++){
        if(nbCash[i]!=0){
            std::cout << nbCash[i] << "x" << cash[i]<< " euros " << std::endl;

        }
    }

    return 0;
}