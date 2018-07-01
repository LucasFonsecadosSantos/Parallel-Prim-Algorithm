#ifndef PRIM_APP_H
#define PRIM_APP_H 1

#include "../entity/Graph.hpp"
#include <vector>
#include <string>

class Prim {
	
	public:
		Prim(std::vector<std::string> *vertexSet, std::vector<int*> *weightMatrix, int cardinality);
		~Prim();
        void primExec();
		std::string printMST();

	private:
		std::vector<std::string> *vertexSet;
		int **graph;
		int vertexSetCardinality;
		int *parent;
		int *key;
		bool *mstSet;
		int minKey(int key[], bool mstSet[]);
		int ** updateWeightMatrix(std::vector<int*> *weightMatrix);
		void setVertexSetCardinality(int cardinality);


};

#endif