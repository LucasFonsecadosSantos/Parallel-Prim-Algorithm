#ifndef GRAPH_ENTITY_H
#define GRAPH_ENTITY_H 1

#include <vector>
#include <string>

class Graph {
	
	public:
		Graph(std::vector<std::string> *vertexSet, std::vector<std::string*> *edgeSet);
		~Graph();
		std::vector<int*> * getAdjacencyMatrix();
		std::vector<std::string> * getVertexSet();
		std::vector<std::string*> * getEdgeSet();
		std::string toString();

	private:
		int vertexSetCardinality;
		int edgeSetCardinality;
		std::vector<int*> *adjacencyMatrix;
		std::vector<std::string> *vertexSet;
		std::vector<std::string*> *edgeSet;
		void adjacencyMatrixPadding();
		void setVertexSet(std::vector<std::string> *vertexSet);
		void setEdgeSet(std::vector<std::string*> *edgeSet);
		void setEdgeSetCardinality(int cardinality);
		void setVertexSetCardinality(int cardinality);
		int getEdgeSetCardinality();
		int getVertexSetCardinality();
		int mappingVertexToIndex(std::string vertex);
		std::string mappingIndexToVertex(int index);
};

#endif