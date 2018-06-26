#include "../../include/view/Gui.hpp"
#include <iostream>

void Gui::printSuceffullyMessage(std::string msg) {
    std::cout << "\033[0;97m" << "[" << "\033[0;92m" << "OK" << "\033[0;97m" << "] " << "\033[0;92m" << msg << "\033[0m";
}