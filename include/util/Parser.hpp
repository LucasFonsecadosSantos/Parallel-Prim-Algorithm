#ifndef PARSER_UTIL_H
#define PARSER_UTIL_H 1

#include "../dao/FileHandler.hpp"
#include <string>
#include <vector>

class Parser {
	
    public:
        Parser(FileHandler *fileHandler);
        ~Parser();
        std::vector<std::string> * getVertexSet();
        std::vector<std::string*> * getEdgeSet  ();

    private:
        char *alphabet;
        std::string delimiter;
        std::string *reservedWords;
        std::vector<std::string> *vertexSet;
        std::vector<std::string*> *edgeSet;
        FileHandler *fileHandler;
        std::string * getTokens(std::string line);
        bool vertexFlag;
        bool edgeFlag;
        bool lexemeValidator(std::string line);
        void populatesSet();

};

#endif