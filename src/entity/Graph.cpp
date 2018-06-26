#include "../../include/entity/Graph.hpp"
#include "../../include/view/Gui.hpp"
#include <string>
#include <cstddef>
#include <iostream>

Graph::Graph(std::vector<std::string> *vertexSet, std::vector<std::string*> *weightSet) {
    this->adjacencyMatrix = NULL;
    setVertexSetCardinality(vertexSet->size());
    setEdgeSetCardinality(edgeSet->size());
    setEdgeSet(edgeSet);
    setVertexSet(vertexSet);
    adjacencyMatrixPadding();
}

void Graph::adjacencyMatrixPadding() {
    int vertexCardinality = getVertexSetCardinality();
    int edgeCardinality = getEdgeSetCardinality();
    std::string *edgeTokens;
    this->adjacencyMatrix = new int*[vertexCardinality];
    //Gui::printSuceffullyMessage("edgeTokens[j]");
    for (int i=0; i < vertexCardinality ; ++i) {
        this->adjacencyMatrix[i] = new int[vertexCardinality];
    }
    
    for (int i=0 ; i < edgeCardinality ; ++i) {
        edgeTokens = this->edgeSet->at(i);
        for (int j=0 ; j < edgeTokens->length() ; ++j) {
            //Gui::printSuceffullyMessage("edgeTokens[j]");
        }
    }
}

inline void Graph::setVertexSet(std::vector<std::string> * vertexSet) {
    this->vertexSet = vertexSet;
}

inline void Graph::setEdgeSet(std::vector<std::string*> *edgeSet) {
    this->edgeSet = edgeSet;
}

inline int Graph::getVertexSetCardinality() {
    return this->vertexSetCardinality;
}

inline int Graph::getEdgeSetCardinality() {
    return this->edgeSetCardinality;
}

inline void Graph::setVertexSetCardinality(int cardinality) {
    this->vertexSetCardinality = cardinality;
}

inline void Graph::setEdgeSetCardinality(int cardinality) {
    this->edgeSetCardinality = cardinality;
}

int Graph::mappingVertexToIndex(std::string vertex) {
    int i=0;
    for (int i = 0 ; i < this->vertexSetCardinality ; ++i) {
        if (this->vertexSet->at(i) == vertex) {
            return i;
        }
    }
    return i;
}

std::string Graph::mappingIndexToVertex(int index) {
    return this->vertexSet->at(index);
}