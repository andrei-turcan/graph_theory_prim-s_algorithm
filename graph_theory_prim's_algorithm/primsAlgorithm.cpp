#include "primsAlgorithm.h"
#include <iostream>
#include <set>

using namespace std;

void primsAlgorithm(const Graph& graph) {
	if (graph.size() == 0) {
		cout << "Graph size = 0!" << endl;
		return;
	}

	set<int> visitedVertices;

	// выбираем начальную вершину
	const int startVertex = 0;
	visitedVertices.insert(startVertex);

	const int maxEdgeWeight = 1000000;

	// переменные, в которых хранятся вершины наиболее подходящего ребра
	int firstVertexOfEdge = 0;
	int secondVertexOfEdge = 0;

	// для нахождения ребра с минимальным весом
	int minEdgeWeight;

	cout << "{ ";
	while (visitedVertices.size() < static_cast<size_t>(graph.size())) {
		// задаем самый высокий вес, для нахождения минимального веса
		minEdgeWeight = maxEdgeWeight;

		// пробегаем все посещенные вершины
		for (const auto& i : visitedVertices) {
			// пробегаем все смежные с посещенными вершины, исключая уже посещенные
			// если обнаружено более "легкое" ребро - запоминаем его
			for (int j = 0; j < graph.size(); j++) {
				if (
					(graph.get(i, j)) && 
					(visitedVertices.find(j) == visitedVertices.end()) && 
					(minEdgeWeight > graph.get(i, j))
					) {
					minEdgeWeight = graph.get(i, j);
					firstVertexOfEdge = i;
					secondVertexOfEdge = j;
				}
			}
		}

		// выводим наиболее легкое ребро
		cout << "(" << firstVertexOfEdge << ", " << secondVertexOfEdge << ") ";

		// добавляем в множество посещенных вершин вершину, смежную с этим ребром
		visitedVertices.insert(secondVertexOfEdge);
	}
	cout << "}" << endl;
}