#include "../../include/util/Parser.hpp"
#include "../../include/dao/FileHandler.hpp"
#include <iostream>
#include <cstring>
#include <vector>

Parser::Parser(FileHandler *fileHandler) {
    this->vertexFlag = this->edgeFlag = false;
    this->vertexSet = new std::vector<std::string>();
    this->edgeSet = new std::vector<std::string*>();
    this->fileHandler = fileHandler;
    this->alphabet = new char[64] {
        'A','a','B','b','C','c','D','d','E','e','F','f',
        'G','g','H','h','I','i','J','j','K','k','L','l',
        'M','m','N','n','O','o','P','p','Q','q','R','r',
        'S','s','T','t','U','u','V','V','W','w','X','x',
        'Y','y','Z','z','0','1','2','3','4','5','6','7',
        '8','9',':',' '
    };
    this->reservedWords = new std::string[2];
    this->reservedWords = new std::string[2] {"::VERTEXES::", "::EDGES::"};
    this->delimiter = "::";
    populatesSet();
}

Parser::~Parser() {

}

bool Parser::lexemeValidator(std::string line) {
    int i=0, j=0;
    int alphabetSize = std::strlen(this->alphabet);;
    int lineSize = line.length();
    bool found = false;
    for (i=0 ; i < alphabetSize ; ++i) {
        for (j=0 ; j < lineSize ; ++j) {
            if (line.at(j) == this->alphabet[i]) {
                found = true;
            }
        }
    }
    return found;
    
}

void Parser::populatesSet() {
    std::string line = "";
    while (this->fileHandler->hasLine()) {
        line = this->fileHandler->readLine();
        if (lexemeValidator(line)) {
            if (line.at(0) == ':' && line.at(1) == ':') {
                if (line == this->reservedWords[0]) {
                    this->vertexFlag = true;
                    this->edgeFlag = false;
                } else if (line == this->reservedWords[1]) {
                    this->edgeFlag = true;
                    this->vertexFlag = false;
                }
            } else {
                if (this->vertexFlag) {
                    this->vertexSet->push_back(line);
                } else {
                    std::string *tokens = new std::string[3];
                    tokens = getTokens(line);
                    std::cout << tokens[0] << tokens[1] << tokens[2] << std::endl;
                    this->edgeSet->push_back(tokens);
                }
            }
        } else {
            //DISPARA ERRO LEXEMA INVALIDO
        }
    }
}

std::string* Parser::getTokens(std::string line) {
    int i=0;
    int tokenCounter = 0;
    int sizeLine = line.length();
    std::string tmpString = "";
    std::string *tokens = new std::string[3];

    for (i=0 ; i < sizeLine && tokenCounter < 3; ++i) {
        if ((line.at(i) == ' ') && i!=0) {
            tokens[tokenCounter] = tmpString;
            tmpString = "";
            ++tokenCounter;
        } else {
            tmpString += line.at(i);
        }
    }
    tokens[tokenCounter] = tmpString;
    return tokens;
}

std::vector<std::string*>* Parser::getEdgeSet() {
    return this->edgeSet;
}

std::vector<std::string>* Parser::getVertexSet() {
    return this->vertexSet;
}