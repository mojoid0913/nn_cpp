#pragma once
#include <vector>

class Matrix {
private:
  std::vector<double> vec;
  int rows;
  int cols;
	int size;
public:
	Matrix(int rows, int cols, bool zero = false);
	Matrix add(Matrix Mat);
  Matrix multiply(Matrix Mat);
  Matrix transpose();
  void print();

	int getRows() { return rows; }
	int getCols() { return cols; }
	int getSize() { return size; }
	double get(int i) { return vec[i]; }
	void set(int i, double val) { vec[i] = val; }
};
