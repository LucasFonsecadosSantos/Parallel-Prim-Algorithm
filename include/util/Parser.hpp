#ifndef PARSER_UTIL_H
#define PARSER_UTIL_H 1

#include <string>

class Parser {
	
	public:
		Parser();
		~Parser();
        void getVertexSet();

	private:
        char *alphabet;
        std::string delimiter;
        std::string *reservedWords;
        bool lexemeValidator(std::string line);

};

#endif