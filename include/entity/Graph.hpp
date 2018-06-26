#ifndef GRAPH_ENTITY_H
#define GRAPH_ENTITY_H 1

#include <vector>

class Graph {
	
	public:
		Graph(std::vector<int> *vertexSet, std::vector<int*> *weightSet);
		~Graph();
		inline int ** getAdjacencyMatrix();
		inline std::vector<int> * getVertexSet();

	private:
		void adjacencyMatrixPadding(std::vector<int> *vertexSet);
};

#endif