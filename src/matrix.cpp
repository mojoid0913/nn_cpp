#include <iostream>
#include <vector>
#include <random>
#include "matrix.h"

using namespace std;

mt19937 gen(42);
uniform_real_distribution<double> dist(-0.1, 0.1);


Matrix::Matrix(int rows, int cols, bool zero) {
  this->rows = rows;
  this->cols = cols;
	vec.resize(rows, vector<double>(cols,0.0));
	
	if (!zero) {
		for(int i = 0; i < rows; i++) {
    	for (int j=0; j<cols; j++)
      	vec[i][j] = dist(gen);
  	}
	}
}

Matrix Matrix::add(Matrix Mat) {
	Matrix result(this->rows, this->cols,true);

	for (int i = 0; i < this->rows; i++) {
    for(int j = 0; j < this->cols; j++)
			result.vec[i][j] = Mat.vec[i][j] + vec[i][j];
	}

	return result; 
}

Matrix Matrix::multiply(Matrix Mat) {
	if (Mat.rows != this->cols) throw invalid_argument("Matrix size mismatch");
	Matrix result(this->rows, Mat.cols, true);

	for (int i = 0; i < this->rows; i++) {
    for(int j=0; j < Mat.cols;j++) {
			for(int k=0; k < this->cols;k++)
				result.vec[i][j] += vec[i][k] * Mat.vec[k][j];
		}
	}

	return result;
}

Matrix Matrix::transpose() {
	Matrix temp(this->cols,this->rows);

	for (int i=0; i < this->rows; i++) {
		for (int j=0; j<this->cols; j++) {
			temp.vec[j][i]=vec[i][j];
		}
	}
	return temp;
}

void Matrix::print() {
  for (int i = 0; i < this->rows; i++) {
    for(int j=0; j < this->cols;j++)
			cout << vec[i][j] << " ";
		cout << "\n";
	}
}
