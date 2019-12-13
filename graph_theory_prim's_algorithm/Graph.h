#pragma once

#include <vector>
#include <string>

class Graph {
private:
	std::vector<std::vector<int>> matrix;
	int matrixSize = 0;
public:
	Graph(const std::string& file);
	int size() const;
	int get(const int& i, const int& j) const;
	void set(const int& i, const int& j, const int& value);
	void loadFromFile(const std::string& file);
	void print() const;
};