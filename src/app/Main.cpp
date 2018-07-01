#include "../../include/dao/FileHandler.hpp"
#include "../../include/util/Parser.hpp"
#include "../../include/entity/Graph.hpp"
#include "../../include/app/Prim.hpp"
#include "../../include/view/Gui.hpp"
#include <iostream>

void checkParams(int paramAmount) {
	if (paramAmount > 2) {
		std::cerr << "Quantidade de parametros invalida!";
	}
}

int main(int argc, char *argv[]) {

	checkParams(argc);
	Parser *parser = new Parser(new FileHandler(argv[1]));
	Gui::printSuceffullyMessage("File Inputed!");
	Gui::printSuceffullyMessage("Paser Done!");
	Graph *graph = new Graph(parser->getVertexSet(), parser->getEdgeSet());
	Gui::printSuceffullyMessage("Graph Done!");
	Gui::printLogMessage("Graph G", graph->toString());
	Prim *prim = new Prim(parser->getVertexSet(), graph->getAdjacencyMatrix(), graph->getVertexSetCardinality());
	Gui::printLogMessage("EXECUTING","Prim algorithm.");
	prim->primExec();
	Gui::printSuceffullyMessage("Prim Algorithm Done!");
	Gui::printLogMessage("MST", "\n"+prim->printMST());
	return 0;
}