#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<int> nombres { -7, 4, 5, -1, 1, 8 };

    std::sort(std::begin(nombres), std::end(nombres), [](int a, int b) -> bool 
    {
        return std::abs(a) < std::abs(b);
    });

    for(int nombre : nombres ){
        std::cout << nombre << std::endl;
    }


    return 0;
}