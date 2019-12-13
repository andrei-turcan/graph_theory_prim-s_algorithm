#include "primsAlgorithm.h"

int main(int argc, char* argv[]) {

	Graph graph("input_matrix.txt");
	graph.print();

	primsAlgorithm(graph);

	system("pause");

	return 0;
}