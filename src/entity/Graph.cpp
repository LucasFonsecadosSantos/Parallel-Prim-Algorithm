#include "../../include/entity/Graph.hpp"
#include "../../include/view/Gui.hpp"
#include <string>
#include <cstddef>
#include <iostream>
#include <vector>
#include <limits.h>
#include <sstream>

Graph::Graph(std::vector<std::string> *vertexSet, std::vector<std::string*> *edgeSet) {
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
    this->adjacencyMatrix = new std::vector<int*>();
    for (int i=0; i < vertexCardinality ; ++i) {
        this->adjacencyMatrix->push_back(new int[vertexCardinality]);
        for (int j=0 ; j < vertexCardinality ; ++j) {
            this->adjacencyMatrix->at(i)[j] = INT_MAX;
        }
    }

    int uVertex, vVertex;
    for (int i=0 ; i < edgeCardinality ; ++i) {
        edgeTokens = this->edgeSet->at(i);
        uVertex = mappingVertexToIndex(edgeTokens[0]);
        vVertex = mappingVertexToIndex(edgeTokens[1]);
        this->adjacencyMatrix->at(uVertex)[vVertex] = atoi(edgeTokens[2].c_str());
    }
}

std::vector<std::string> * Graph::getVertexSet() {
    return this->vertexSet;
}

void Graph::setVertexSet(std::vector<std::string> * vertexSet) {
    this->vertexSet = vertexSet;
}

void Graph::setEdgeSet(std::vector<std::string*> *edgeSet) {
    this->edgeSet = edgeSet;
}

int Graph::getVertexSetCardinality() {
    return this->vertexSetCardinality;
}

int Graph::getEdgeSetCardinality() {
    return this->edgeSetCardinality;
}

void Graph::setVertexSetCardinality(int cardinality) {
    this->vertexSetCardinality = cardinality;
}

void Graph::setEdgeSetCardinality(int cardinality) {
    this->edgeSetCardinality = cardinality;
}

std::vector<int*> *Graph::getAdjacencyMatrix() {
    return this->adjacencyMatrix;
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

std::string Graph::toString() {
    std::ostringstream sstream;
    sstream << "";
    sstream << "G=(V,E) {\n";
    sstream << "\tV=[";
    if (this->vertexSet != NULL && this->edgeSet != NULL && this->adjacencyMatrix != NULL) {
        for (int i = 0 ; i < this->vertexSetCardinality ; ++i) {
            sstream << this->vertexSet->at(i);
            if (i+1 != this->vertexSetCardinality) {
                sstream << ",";
            } 
        }
        sstream <<"];\n\tE=[";
        for (int i = 0 ; i < this->edgeSetCardinality ; ++i) {
            std::string *edge = this->edgeSet->at(i);
            sstream << "\n\t\t("+edge[0] + "," + edge[1] + "," + edge[2] + ")";
            if (i+1 != this->edgeSetCardinality) {
                sstream << ",";
            }
        }
        sstream << "\n\t];\n\tW=[\n\t";
        for (int i=0 ; i < this->vertexSetCardinality ; ++i) {
            if (i==0) {
                sstream << "\t";
            }
            sstream << "\t" << this->vertexSet->at(i) << " ";
        }
        sstream << "\n\t";
        for (int i = 0 ; i < this->vertexSetCardinality ; ++i) {
            sstream << "\t" << this->vertexSet->at(i) << "  ";
            for (int j = 0 ; j < this->vertexSetCardinality; ++j) {
                sstream << " ";
                if (this->adjacencyMatrix->at(i)[j] == INT_MAX) {
                    sstream << "\tinf";
                } else {
                    sstream << "\t" << this->adjacencyMatrix->at(i)[j];
                }
            }
            sstream << "\n\t";
        }
        sstream << "];";
    }
    sstream << "\n}\n";
    return sstream.str();
}