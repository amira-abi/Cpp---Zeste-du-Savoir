#include <iostream>

int main(){

    bool a;
    bool b;

    std::cout << std::boolalpha;
    std::cin >> a ;
    std::cout << " a correspond a "<< a << std::endl;
    std::cin.clear();
    std::cin.ignore(255,'\n');
    std::cin >> b;
    std::cout << " b correspond a "<< a << std::endl;
    std::cout << std::boolalpha; 

    std::cout<< (!(a==b)) << std::endl;
    return 0;
}