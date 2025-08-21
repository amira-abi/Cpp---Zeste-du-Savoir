#include <iostream>
#include <string>
#include <fstream>


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
        
    int nbLign {0};
    int nbChar {0};
    int nbWord {0};
    std::string lign { ""};

    while(std::getline(file, lign)){
        nbLign++;
        for(int i =0; i<std::size(lign), i++){
            if(lign(i).isspace()){
                nbWord++;
            }else{
                nbChar++;
            }
        }
        nbWord++;
        std::cout << "In this lign : '" << lign << "', there is " << nbWord << " words, " << nbChar << " characters."<<std::endl;
        nbWord = 0;
        nbChar =0;
    }
    
    return 0;


}