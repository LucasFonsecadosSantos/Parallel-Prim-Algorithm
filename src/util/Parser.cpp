#include "../../include/util/Parser.hpp"

Parser::Parser() {
    this->alphabet = new char[64] {
        'A','a','B','b','C','c','D','d','E','e','F','f',
        'G','g','H','h','I','i','J','j','K','k','L','l',
        'M','m','N','n','O','o','P','p','Q','q','R','r',
        'S','s','T','t','U','u','V','V','W','w','X','x',
        'Y','y','Z','z','0','1','2','3','4','5','6','7',
        '8','9',':',' '
    };
    this->reservedWords = new std::string[2];
    this->reservedWords = new std::string[2] {"VERTEXES", "EDGES"};
    this->delimiter = "::";
}

Parser::~Parser() {

}

bool Parser::lexemeValidator(std::string line) {
    int i=0, j=0;
    int alphabetSize = this->alphabet.length;
    int lineSize = line.lentgh();
    bool found = false;
    for (i=0 ; i < alphabetSize ; ++i) {
        for (j=0 ; j < lineSize ; ++j) {
            if (line.at(j) == alphabetSize[i]) {
                found = true;
            }
        }
    }
    (found) ? return true : return false;
}