#include "../../include/dao/FileHandler.hpp"

FileHandler::FileHandler() {
    this->buffer = new std::stack<std::string>();
}

FileHandler::~FileHandler() {

}

inline bool FileHandler::hasLine() {
    return !this->buffer->empty();
}

std::string FileHandler::readLine() {
    std::string line = this->buffer->top();
    this->buffer->pop();
    return line;
}

