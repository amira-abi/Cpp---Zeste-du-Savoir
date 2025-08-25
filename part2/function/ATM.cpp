#include <iostream>
#include <array>

/**
 * Calculates the number of bills/coins needed to make up the given amount of money.
 *
 * The function uses a greedy algorithm to determine the minimal number of bills/coins
 * needed to represent the input amount using standard euro denominations.
 *
 * @param money The amount of money to withdraw (in euros).
 * @return A std::array of 9 integers representing the number of each denomination used,
 *         in the following order: 500, 200, 100, 50, 20, 10, 5, 2, 1.
 */
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