#include <iostream>
#include <vector>

int main(){

    std::vector<int> values {-17, 42, -5, 89, -33, 0, 14, -76};
    std::vector<int> even {};
    std::vector<int> odd {};

    for(auto const x : values){
        if(x%2==0){
            even.push_back(x);
        }else{
            odd.push_back(x);
        }
    }
    if(!std::empty(even)){
        std::cout << "Les nombres pairs sont : " << std::endl;
        for(auto const x : even){
            std::cout << x << ", " << std::endl;
        }
    }else{
        std::cout << "Il n'y a pas de nombres pairs" << std::endl;
    }

    if(!std::empty(odd)){
        std::cout << "Les nombres impairs sont : " << std::endl;
        for(auto const x : odd){
            std::cout << x << ", " << std::endl;
        }
    }else{
        std::cout << "Il n'y a pas de nombres impairs" << std::endl;
    }
}