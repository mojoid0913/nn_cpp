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
	this->size =rows * cols;
	vec.resize(size, 0.0);
	if (!zero) {
		for(int i=0;i<size;i++)
			vec[i] = dist(gen);
	}
	//stride 개념 필요. (transpose 효율을 위해)
}

Matrix Matrix::add(Matrix Mat) {
	Matrix result(this->rows,this->cols,true);

	for (int i = 0; i < this->size; i++)
		result.vec[i] = Mat.vec[i] + vec[i];

	return result; 
}

Matrix Matrix::multiply(Matrix Mat) {
	if (Mat.rows != this->cols) throw invalid_argument("Matrix size mismatch");
	Matrix result(this->rows, Mat.cols, true);

	for (int i = 0; i < this->size; i++)
    for (int k = 0; k < this->cols; k++)
        result.vec[i] += vec[i/cols * cols + k] * Mat.vec[k * Mat.cols + i%Mat.cols];

	return result;
}

Matrix Matrix::transpose() {
	Matrix temp(cols,rows,true);
	for (int i=0; i < this->rows; i++) {
		for (int j=0; j < this->cols; j++) {
			temp.vec[j*cols+i] = vec[i*cols+j];
		}
	}
	return temp;
}

void Matrix::print() {
	for (int i = 0; i < size; i++) {
			cout << vec[i] << " ";
			if(i%cols==cols-1) cout << "\n";
	}
}
