#include <iostream>
#include <optional>
#include <limits>

/**
 * Displays an error message indicating that the input is invalid
 * then clears and ingnore the input stream to prepare for new input
 */
void clearInput(){
    std::cout << "You're input is not correct, try again !" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}


template <typename T, typename Predicate>
T askValue(const std::string question, T& input, Predicate predicate){
    std::cout << question << std::endl;
    while(!(std::cin>>input) || predicate(input)){
        if (std::cin.eof()){
            throw std::runtime_error("The flux is closed !");
        }else if (std::cin.fail()){
            clearInput();
        }else{
            std::cout << "The predicate was not respected !" << std::endl;
        }
    }
    return input;
}


int main(){
    int day {0};
    int month  {0};
    int year {0};
    double size {0.0};

    month = askValue("On what month were you born ? ", month, [](int month)-> bool {return (month > 12) || (month < 1);}) ;
    
    if(month==2){
        day = askValue("On what day were you born ? ", day, [](int day) -> bool {return (day<1 || day > 28);});
    }else{
        day = askValue("On what day were you born ? ", day, [](int day) -> bool {return (day<1 || day > 31);});
    }

    year = askValue("On what year were you born", year, [](int year) -> bool {return (year < 2025);} );

    size = askValue("What is you're size ? (in cm)", size,[](int size) -> bool {return (size < 0.0);});

    std::cout << "You we're born on " << day << "/" << month << "/" << year << std::endl;
    std::cout<< "You're size is " << size << " m"<< std::endl;

    return 0;
}