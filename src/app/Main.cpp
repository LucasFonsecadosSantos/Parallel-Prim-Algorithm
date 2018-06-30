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
	Parser *parser = new Parser(new FileHandler(argv[1]));
	Graph *graph = new Graph(parser->getVertexSet(), parser->getEdgeSet());
	std::cout << graph->toString();
	Prim *prim = new Prim(graph->getAdjacencyMatrix(), graph->getVertexSetCardinality());
	prim->primExec();
	return 0;
}