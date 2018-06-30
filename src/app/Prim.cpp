#include "../../include/app/Prim.hpp"
#include <stdio.h>
#include <limits.h>
#include <iostream>

Prim::Prim(std::vector<int*> *weightMatrix, int cardinality) {
    this->graph = updateWeightMatrix(weightMatrix);
    setVertexSetCardinality(cardinality);
}

Prim::~Prim() {
    
}

void Prim::setVertexSetCardinality(int cardinality) {
    this->vertexSetCardinality = cardinality;
}

int Prim::minKey(int key[], bool mstSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < this->vertexSetCardinality; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
/*int Prim::printMST(int parent[], int n, int graph[V][V]) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}*/
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation

int **Prim::updateWeightMatrix(std::vector<int*> *weightMatrix) {
    int cardinality = weightMatrix->size();
    int **updatedWeightMatrix = new int*[cardinality];
    for (int i = 0 ; i < cardinality ; ++i) {
        updatedWeightMatrix[i] = new int[cardinality];
        for (int j = 0 ; j < cardinality ; ++j) {
            if (weightMatrix->at(i)[j] == INT_MAX) {
                updatedWeightMatrix[i][j] = 0;
            } else {
                updatedWeightMatrix[i][j] = weightMatrix->at(i)[j];
            }
        }
    }
    return updatedWeightMatrix;
}

void Prim::primExec() {

    int parent[this->vertexSetCardinality]; // Array to store constructed MST
    int key[this->vertexSetCardinality];   // Key values used to pick minimum weight edge in cut
    bool mstSet[this->vertexSetCardinality];  // To represent set of vertices not yet included in MST
    
     // Initialize all keys as INFINITE
    for (int i = 0; i < this->vertexSetCardinality; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST 
    
     // The MST will have V vertices
    for (int count = 0; count < this->vertexSetCardinality-1; count++) {
        std::cout << "chegou aqui";
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        std::cout << mstSet[u];
        mstSet[u] = true; //PROBLEMA TA AQUI
        /*
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < this->vertexSetCardinality; v++)
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];*/
    }
 
    // print the constructed MST
    //printMST(parent, V, graph);
}