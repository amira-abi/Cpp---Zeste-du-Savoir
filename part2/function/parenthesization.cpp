#include <iostream>
#include  <string>

/** 
 * Count the difference between opening and closing parentheses
 * @param expression the string expression to check
 * @return an integer representing the balence of parentheses
 *          - 0 means balanced,
 *          - positive means more '()'
 *          - negative means more ')'
 */
int counter(std::string expression){
    int nbPar = 0;
    for(char x : expression){
        if(x=='('){
            nbPar++;
        }else if( x==')'){
            nbPar--;
        }
    }
    return nbPar;
}

/**
 * Prints wether the eexpression is properly parenthesized or not
 * @param nbPar ths integer represent the difference between opening and closing parentheses
 *              a value of 0 means balanced parentheses
 * @param expression the string expression to check and display
 */
void isItCorrect(int nbPar, std::string expression){
    std::cout << nbPar << std::endl;
    if((nbPar==0)){
        std::cout << "This expression '" << expression <<"' is properly parenthesized." << std::endl;
    }else{
        std::cout<< "This expression '"<< expression << "' is not properly parenthesized."<<std::endl;
    }
}


int main(){
    std::string correctExpression {"(())"};
    std::string wrongExpression {"(()))(()"};

    isItCorrect(counter(correctExpression), correctExpression);
    isItCorrect(counter(wrongExpression), wrongExpression);

    return 0;
}