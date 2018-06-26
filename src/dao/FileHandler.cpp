#include "../../include/dao/FileHandler.hpp"
#include <fstream>
#include <iostream>
#include <stack>

FileHandler::FileHandler(const char *fileName) {
    this->buffer = new std::stack<std::string>();
    readFile(fileName);
}

FileHandler::~FileHandler() {

}

bool FileHandler::hasLine() {
    return !this->buffer->empty();
}

std::string FileHandler::readLine() {
    std::string line = this->buffer->top();
    this->buffer->pop();
    return line;
}

void FileHandler::readFile(const char* fileName) {
	this->inputFile.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
    if(this->inputFile.is_open()) {
    	std::string line = "";
        while(this->inputFile) {
            getline(this->inputFile, line);
            if(line == "") {
                continue;
            }else {
            	this->buffer->push(line);
            }
        }
    }
	this->inputFile.close();
}

