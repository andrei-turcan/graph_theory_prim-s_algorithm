#include "Graph.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Graph::Graph(const std::string& file) {
	loadFromFile(file);
}

int Graph::size() const {
	return matrixSize;
}

int Graph::get(const int& i, const int& j) const {
	if ((i >= 0) && (j >= 0) && (i <= size()) && (j <= size())) {
		return matrix[i][j];
	}
	else
		return -1;
}

void Graph::set(const int& i, const int& j, const int& value) {
	matrix[i][j] = value;
}

void Graph::loadFromFile(const std::string& file) {
	ifstream inputFile(file);

	inputFile >> matrixSize;
	matrix.resize(size());
	for (int i = 0; i < size(); i++)
		matrix[i].resize(size());

	int temp;
	// skip first line
	for (int i = 0; i < size(); i++)
		inputFile >> temp;
	for (int i = 0; i < size(); i++) {
		// skip first number
		inputFile >> temp; 
		for (int j = 0; j < size(); j++) {
			inputFile >> temp;
			set(i, j, temp);
		}
	}

	inputFile.close();
}

void Graph::print() const {
	const unsigned char vert = 179;
	const unsigned char horiz = 196;
	const unsigned char corner = 218;

	cout << "    ";
	for (int j = 0; j < size(); j++)
		cout << setw(3) << j;
	cout << endl;

	cout << "   " << corner;
	for (int j = 0; j < size() * 3; j++)
		cout << horiz;
	cout << endl;

	for (int i = 0; i < size(); i++) {
		cout << setw(2) << i << " " << vert;
		for (int j = 0; j < size(); j++)
			cout << setw(3) << get(i, j);
		cout << endl;
	}
	cout << endl;
}
