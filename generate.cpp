#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <time.h>

//#define N 200

int main() {
	long int N = 850;
	std::ostringstream sstream;
	sstream << "::VERTEXES::\n";


	for (long long int i=0 ; i < N ; ++i) {
		sstream << "V" << i << "\n";
	}

	long int adjacencyMatrix[N][N];
	srand(time(NULL));
	//E > |V²|
	for (long int i=0 ; i < N ; ++i)
		for (long int j=0 ; j < N ; ++j)
			adjacencyMatrix[i][j] = rand()%100;


	for (int i=0 ; i < 50 ; ++i) {
		for (int j=0 ; j < 50 ; ++j) {
			std::cout << adjacencyMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}


	
	return 0;
}