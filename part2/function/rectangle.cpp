#include <iostream>

void rectangle(int height, int width){
    int a = 0;
    int b = 0;
    while(a<height){
        while(b<width){
            std::cout << "*";
            b++;
        }
        std::cout << '\n';
        b=0;
        a++;
    }    
}

int main(){
    int height = 0;
    int width = 0;

    std::cout << "Enter the height value : "<< std::endl;
    while(!(std::cin >> height)|| height<1){
        std::cout << "The value is wrong, try again..."<< std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }

    std::cout << "Enter the width value : "<< std::endl;
    while(!(std::cin >> width) || width<1){
        std::cout << "The value is wrong, try again..."<< std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }

    rectangle(height, width);
    return 0;

}