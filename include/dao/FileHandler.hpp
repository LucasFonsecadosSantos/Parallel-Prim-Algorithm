#ifndef FILE_HANDLER_DAO_H
#define FILE_HANDLER_DAO_H 1

#include <stack>
#include <string>
#include <fstream>

class FileHandler {
	
	public:
		FileHandler(const char* fileName);
		~FileHandler();
        std::string readLine();
        bool hasLine();

	private:
        std::stack<std::string> *buffer;
        void readFile(const char* fileName);
        std::fstream inputFile;

};

#endif