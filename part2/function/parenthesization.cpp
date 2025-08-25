#include <iostream>
#include  <string>

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