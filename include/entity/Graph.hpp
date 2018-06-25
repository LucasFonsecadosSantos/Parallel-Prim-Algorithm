#ifndef GRAPH_ENTITY_H
#define GRAPH_ENTITY_H 1

class Graph {
	
	public:
		Graph();
		~Graph();
		inline int ** getAdjacencyMatrix();
		inline std::vector<int> * getVertexSet();

	private:
		void adjacencyMatrixPadding(std::vector<int> *vertexSet);
};

#endif