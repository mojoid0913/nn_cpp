#pragma once
#include <vector>

enum InitType {
	ZERO,
	RANDOM,
	LECUN,
	XAVIER,
	HE,
	ORTHOGONAL
};

class Matrix {
private:
  int rows;
  int cols;
	int size;
public:
  std::vector<double> vec;
	
	int getRows() { return rows; }
	int getCols() { return cols; }
	int getSize() { return size; }

	//Matrix(int rows, int cols, bool zero = false);
	Matrix(int rows, int cols, InitType type = RANDOM);
	Matrix add(Matrix Mat);
  Matrix multiply(Matrix Mat);
  Matrix transpose();
  void print();
};
