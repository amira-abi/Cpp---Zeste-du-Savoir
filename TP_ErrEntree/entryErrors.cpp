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


/**
 * Check if hte user's input is within the range defined by
 * 'limitA' and 'limitB'. If the input is out of bounds, it
 * clears the input stream and notifies the user
 * 
 * @param input the user's input to validate
 * @param limitA the lower bound 
 * @param limitB the upper bound 
 * @return true if it's correct, false otherwise
 */
template <typename T>
T checkInput(std::optional<T> limitA, std::optional<T> limitB, T& input){
    while (!(std::cin >> input) || (limitA && input < limitA.value()) || (limitB && input > limitB.value())){
        std::cout << "Value out of bounds" << std::endl;
        clearInput();
    }

    return input;
}

/**
 * Check if hte user's input is within the range defined by
 * 'limitA' and 'limitB'. If the input is out of bounds, it
 * clears the input stream and notifies the user
 * 
 * @param input the user's input to validate
 * @param limitA the lower bound 
 * @return true if it's correct, false otherwise
 
double checkInput(double limitA, std::string question, double & input){
    input = askUser(question, input);
    while (input < limitA){
        std::cout << "Value out of bounds" << std::endl;
        clearInput();
        input = askUser(question, input);
    }

    return input;
}*/

int main(){
    int day {0};
    int month  {0};
    int year {0};
    double size {0.0};

    /**auto checkInput = [](auto & input, auto predicate) -> bool {
        while(!(std::cin >> input || !predicat(input))){
            if (std::cin.eof())
            {
                throw std::runtime_error("Input stream has been closed!")
            }else if (std::cin.fail()){
                clearInput();
            }else{
                std::cout<< "The predicate was not respected !"<< std::endl;
            }
    }
        return input;
    }*/

    std::cout<<"On what month were you born ? "<< std::endl;
    month = checkInput<int>(std::optional<int>{1}, std::optional<int>{12}, month) ;
    
    if(month==2){
        std::cout<<"On what day were you born ? " << std::endl;
        day = checkInput<int>(std::optional<int>{1}, std::optional<int>{28}, day);
    }else{
        std::cout<< "On what day were you born ? " << std::endl;
        day = checkInput<int>(std::optional<int>{1}, std::optional<int>{31}, day);
    }

    std::cout << "On what year were you born" << std::endl;
    year = checkInput<int>(std::optional<int>{}, std::optional<int>{2025} , year);

    std::cout << "What is you're size ? (in cm)" << std::endl;
    size = checkInput<double>(std::optional<double>{0.0}, std::optional<double>{}, size);

    std::cout << "You we're born on " << day << "/" << month << "/" << year << std::endl;
    std::cout<< "You're size is " << size << " m"<< std::endl;

    return 0;
}