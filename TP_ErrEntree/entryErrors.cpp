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
        if (std::cin.eof())
        {
            throw std::runtime_error("Input stream has been closed!")
        }else{
            clearInput();
            std::cout<< "You're suppose to give an int !"<< std::endl;
        }
    }

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
        if (std::cin.eof())
        {
            throw std::runtime_error("Input stream has been closed!")
        }else
        {
            clearInput();
            std::cout<< "You're suppose to give an int !"<< std::endl;
        }
        std::cout<< "You're suppose to give an int !"<< std::endl;
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
 * @param limitB the upper bound 
 * @return true if it's correct, false otherwise
 */
int checkInput(std::optional<int> limitA, std::optional<int> limitB, std::string question, int & input){
    input = askUser(question, input);
    while ((limitA && input < limitA.value()) || (limitB && input > limitB.value())){
        std::cout << "Value out of bounds" << std::endl;
        clearInput();
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
        clearInput();
        input = askUser(question, input);
    }

    return input;
}

int main(){
    int day {0};
    int month  {0};
    int year {0};
    double size {0.0};

    auto askUser = [](const std::string & question){
        auto input;
        std::cout << question;
        while(!(std::cin >> input || !inputHaveGoodSize(input))){
        if (std::cin.eof())
        {
            throw std::runtime_error("Input stream has been closed!")
        }else{
            clearInput();
            std::cout<< "You're suppose to give an int or a double(size) !"<< std::endl;
        }
        std::cout<< "You're suppose to give an int !"<< std::endl;
    }
        return input;
    }

    askUser("On what month were you born ? ");
    month = checkInput(1, 12, month) ;
    
    if(month==2){
        askUser("On what day were you born ? ");
        day = checkInput(1, 28, day);
    }else{
        askUser("On what day were you born ? ");
        day = checkInput(1, 31, day);
    }

    askUser("On what year were you born");
    year = checkInput(std::nullopt, 2025 , year);

    askUser("What is you're size ? (in cm)");
    size = checkInput(0.0, size);

    std::cout << "You we're born on " << day << "/" << month << "/" << year << std::endl;
    std::cout<< "You're size is " << size << " m"<< std::endl;

    return 0;
}