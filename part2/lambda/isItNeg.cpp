#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> const nombres { 1, 2, 3, 4, 5, 6, -7 };

    if (std::any_of (nombres.begin(), nombres.end(), [](int n)-> bool
    { 
        return n<0;}))
    {    
        std::cout<< "tous les nombres ne sont pas négatifs" << std::cout;
    }else{
        std::cout<< "tous les nombres sont négatifs" << std::endl;

    }
    
}