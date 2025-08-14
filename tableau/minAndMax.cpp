#include <iostream>
#include <vector>

int main(){
    
    std::vector<int> values {-17, 42, -5, 89, -33, 0, 14, -76};
    int min {values[0]};
    int max {values[0]};

    for( auto const x : values){
        if(x<min){
            min = x;
        }else if(x>max){
            max = x;
        }
    }

    std::cout << " La liste de nombre est" << std::endl;
    for(auto const x : values){
        std::cout << x << ", " << std::endl;
    }

    std::cout << "Le plus petit élément du tableau est : "<< min << std::endl;
    std::cout << "Le plus grand élément du tableau est : "<< max << std::endl;

    return 0;
}