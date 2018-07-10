#include "../../include/app/Prim.hpp"
#include "../../include/entity/Graph.hpp"
#include <stdio.h>
#include <limits.h>
#include <sstream>
#include <iostream>
#include <string>
#include "mpi.h"

Prim::Prim(std::vector<std::string> *vertexSet, std::vector<int*> *weightMatrix, int cardinality) {
    this->graph = updateWeightMatrix(weightMatrix);
    this->vertexSet = vertexSet;
    this->parent = new int[cardinality]; // Array to store constructed MST
    this->key = new int[cardinality];   // Key values used to pick minimum weight edge in cut
    this->mstSet = new bool[cardinality];  // To represent set of vertices not yet included in MST
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
        if (this->mstSet[v] == false && this->key[v] < min)
            min = this->key[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
std::string Prim::printMST() {
    std::ostringstream sstream;
    sstream << "Edge   Weight\n";
    for (int i = 1; i < this->vertexSetCardinality; i++) {
        sstream  << this->vertexSet->at(this->parent[i]) << " - " << this->vertexSet->at(i) << "\t" << this->graph[i][this->parent[i]] << "\n";
    }
    return sstream.str();
}
 
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

void Prim::primExec(int argc, char *argv[]) {
    MPI_Status Stat;
    int numtasks, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int result[this->vertexSetCardinality];
    int u = 0;
    int global = 0;

     // Initialize all keys as INFINITE
    for (int i = 0; i < this->vertexSetCardinality; i++)
        this->key[i] = INT_MAX, this->mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
    this->key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    this->parent[0] = -1; // First node is always root of MST 
    
     // The MST will have V vertices
    for (int count = 0; count < this->vertexSetCardinality-1; count++) {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        
        int u = minKey(key, mstSet);
        MPI_Allreduce(&u, &global, 1, MPI_INT, MPI_MIN,MPI_COMM_WORLD);
        std::cout << "GLOBAL: " << global << " " << rank;

        // Add the picked vertex to the MST Set
        //std::cout << u;
        //std::cout << std::endl << "u: " << u << mstSet[u] << " " <<  (sizeof (mstSet) / sizeof (bool));
        this->mstSet[u] = true; //PROBLEMA TA AQUI
        
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        // MPI_Scatter(&graph, this->vertexSetCardinality/numtasks, MPI_INT, &u, this->vertexSetCardinality/numtasks, MPI_INT, 0,
        //       MPI_COMM_WORLD);
        for (int v = 0; v < this->vertexSetCardinality; v++)
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && this->mstSet[v] == false && graph[u][v] <  this->key[v])
                this->parent[v]  = u, this->key[v] = graph[u][v];   
    }
    MPI_Finalize();
    // MPI_Gather(&u,1, MPI_INT, &graph, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    // if(rank == 0){
    //     for(int i=0;i<this->vertexSetCardinality;i++){
    //         std:: cout<< result[i];
    //     }
    // }  
}