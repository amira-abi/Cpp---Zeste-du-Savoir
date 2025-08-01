#include <iostream>

int main(){
    std::cout << " Quelle age as tu ?" << std::endl;
    int age;
    std::cin >> age;
    while(!(std::cin >> age)){
        std::cout << "Tu dois rentrer un chiffre ! Recommence..." << std::endl;
        std::cin.clear();
        std::cin.ignore(255,'\n');
    }

    std::cout << "Tu as " << age << " ans."<< std::endl;
    return 0;
}