#include <iostream>
#include <optional>
#include <limits>

/**
 * Displays an error message indicating that the input is invalid
 * then clears and ingnore the input stream to prepare for new input
 */
void inputIsNotCorrect(){
    std::cout << "You're input is not correct, try again !" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

bool inputHaveGoodSize(int & input){
    return ( input >std::numeric_limits<int>::min() && input <std::numeric_limits<int>::max());
}

bool inputHaveGoodSize(double & input){
    return (input > std::numeric_limits<double>::min() && input<std::numeric_limits<double>::max());
}

/**
 * prompts the user with a question and retrives the input.
 * 
 * Display the given question to the standar output and waits for the users 
 * to enter a response.
 * 
 * @param question the message display to the user
 * @return An int containing the user's input
 */
int askUser(std::string question, int & input){
    std::cout << question << std::endl;
    while(!(std::cin >> input || !inputHaveGoodSize(input))){
        inputIsNotCorrect();
        std::cout<< "You're suppose to give an int !"<< std::endl;
    };

    return input;
}

/**
 * prompts the user with a question and retrives the input.
 * 
 * Display the given question to the standar output and waits for the users 
 * to enter a response.
 * 
 * @param question the message display to the user
 * @return A double containing the user's input
 */
double askUser(std::string question, double & input){
    std::cout << question << std::endl;
    while(!(std::cin >> input) || !inputHaveGoodSize(input)){
        inputIsNotCorrect();
        std::cout<< "You're suppose to give an int !"<< std::endl;
    };

    return input;
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
int checkInput(std::optional<int> limitA, std::optional<int> limitB, std::string question, int & input){
    input = askUser(question, input);
    while ((limitA && input < limitA.value()) || (limitB && input > limitB.value())){
        std::cout << "Value out of bounds" << std::endl;
        inputIsNotCorrect();
        input = askUser(question, input);
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
 */
double checkInput(double limitA, std::string question, double & input){
    input = askUser(question, input);
    while (input < limitA){
        std::cout << "Value out of bounds" << std::endl;
        inputIsNotCorrect();
        input = askUser(question, input);
    }

    return input;
}

int main(){
    int day {0};
    int month  {0};
    int year {0};
    double size {0.0};
    month = checkInput(1, 12, "On what month were you born ? ", month) ;
    
    if(month==2){
        day = checkInput(1, 28, "On what day were you born ?", day);
    }else{
        day = checkInput(1, 31, "On what day were you born ?", day);
    }

    year = checkInput(std::nullopt, 2025 , "On what year were you born", year);

    size = checkInput(0.0,"What is you're size ? (in cm)", size);

    std::cout << "You we're born on " << day << "/" << month << "/" << year << std::endl;
    std::cout<< "You're size is " << size << " m"<< std::endl;

    return 0;
}