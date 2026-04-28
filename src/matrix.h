#pragma once
#include <vector>

class Matrix {
private:
  std::vector<std::vector<double>> vec;
  int rows;
  int cols;
public:
	Matrix(int rows, int cols, bool zero = false);
	Matrix add(Matrix Mat);
  Matrix multiply(Matrix Mat);
  Matrix transpose();
  void print();
};
