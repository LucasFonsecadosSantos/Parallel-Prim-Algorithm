#ifndef FILE_HANDLER_DAO_H
#define FILE_HANDLER_DAO_H 1

#include <stack>
#include <string>

class FileHandler {
	
	public:
		FileHandler(const char* fileName);
		~FileHandler();
        std::string readLine();
        inline bool hasLine();

	private:
        std::stack<std::string> buffer;

};

#endif