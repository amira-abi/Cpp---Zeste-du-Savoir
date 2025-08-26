#include <iostream>
#include <string>
#include <fstream>
#include <iterator>


/**
 * This program will give the data off the file , whichs means :
 * numbers of ligns
 * numbers of characteres ( without the spaces)
 * numbers of words
 */
int main(){

    std::ofstream file {"data.txt"};
    file << "I felt all flushed with fever,\n";
    file << "embarrassed by the crowd,\n";
    file << "I felt he found my letters,\n";
    file << "then read each one out loud,\n";
    file << "I prayed that he would finish,\n";
    file << "but he just kept right on,\n";
    file << "Did you guess the song?\n";
    file.close();
        
    int nbLign {0};
    int nbChar {0};
    int nbWord {0};
    std::string lign { "" };
    std::ifstream fileRead {"data.txt"};
    
    std::cout<< "Here's the text :  " << std::endl;
    while (std::getline(fileRead, lign))
    {
        std::cout << lign << std::endl;
    }
    fileRead.close();
    
    std::ifstream fileStat {"data.txt"};

    while(std::getline(fileStat, lign)){
        nbLign++;
        for(char c : lign){
            if(isspace(c)){
                nbWord++;
            }else{
                nbChar++;
            }
        }
        nbWord++;
        std::cout << "In this lign : '" << lign << "', there is " << nbWord << " words, " << nbChar << " characters."<<std::endl;
        nbWord = 0;
        nbChar = 0 ;
    }
    fileStat.close();

    return 0;
}