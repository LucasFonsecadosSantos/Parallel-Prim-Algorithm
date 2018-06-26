#ifndef GRAPH_ENTITY_H
#define GRAPH_ENTITY_H 1

#include <vector>
#include <string>

class Graph {
	
	public:
		Graph(std::vector<std::string> *vertexSet, std::vector<std::string*> *weightSet);
		~Graph();
		inline int ** getAdjacencyMatrix();
		inline std::vector<std::string> * getVertexSet();
		inline std::vector<std::string*> * getEdgeSet();

	private:
		int vertexSetCardinality;
		int edgeSetCardinality;
		int **adjacencyMatrix;
		std::vector<std::string> *vertexSet;
		std::vector<std::string*> *edgeSet;
		void adjacencyMatrixPadding();
		inline void setVertexSet(std::vector<std::string> *vertexSet);
		inline void setEdgeSet(std::vector<std::string*> *edgeSet);
		inline void setEdgeSetCardinality(int cardinality);
		inline void setVertexSetCardinality(int cardinality);
		inline int getEdgeSetCardinality();
		inline int getVertexSetCardinality();
		int mappingVertexToIndex(std::string vertex);
		std::string mappingIndexToVertex(int index);
};

#endif