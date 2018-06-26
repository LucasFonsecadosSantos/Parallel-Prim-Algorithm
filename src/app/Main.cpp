#include "../../include/dao/FileHandler.hpp"
#include "../../include/util/Parser.hpp"
#include "../../include/entity/Graph.hpp"
#include "../../include/app/Prim.hpp"
#include <iostream>

void checkParams(int paramAmount) {
	if (paramAmount > 2) {
		std::cerr << "Quantidade de parametros invalida!";
	}
}

int main(int argc, char *argv[]) {

	checkParams(argc);

	return 0;
}