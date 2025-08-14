#include <iostream>
#include <vector>

int main(){
    std::cout << "Input values : " << std::endl;
    std::vector<int> values {};
    int input {0};
    int sum {0};
    int average {0};
    while(true){
        while(!(std::cin >> input)){
            std::cout << " You have to give a valid integer !" << std::endl;
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        if(input<0){
            break;
        }
        values.push_back(input);
    }
    if(!std::empty(values)){
        for(auto const x : values){
            sum+= x;
        }
        std::cout << " The sum worth : " << sum << std::endl;
        average = sum/(std::size(values));

        std::cout << " The average of the array elements is  : " << average << std::endl;
    }else{
        std::cout << "The array is empty , I can't calculate the average." << std::endl;
    }
    
    return 0;
}