#ifndef PRIM_APP_H
#define PRIM_APP_H 1

#include <vector>

class Prim {
	
	public:
		Prim(std::vector<int*> *weightMatrix, int cardinality);
		~Prim();
        void primExec();
		int printMST(int parent[], int n, int **graph);

	private:
		int **graph;
		int vertexSetCardinality;
		int minKey(int key[], bool mstSet[]);
		int ** updateWeightMatrix(std::vector<int*> *weightMatrix);
		void setVertexSetCardinality(int cardinality);


};

#endif