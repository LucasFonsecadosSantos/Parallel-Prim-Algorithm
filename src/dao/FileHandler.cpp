#include "../../include/dao/FileHandler.hpp"
#include <fstream>
#include <iostream>
#include <vector>

FileHandler::FileHandler(const char *fileName) {
    this->buffer = new std::vector<std::string>();
    readFile(fileName);
}

FileHandler::~FileHandler() {

}

bool FileHandler::hasLine() {
    return !this->buffer->empty();
}

std::string FileHandler::readLine() {
    std::string line = this->buffer->front();
    this->buffer->erase(this->buffer->begin());
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
            	this->buffer->push_back(line);
            }
        }
    }
	this->inputFile.close();
}

