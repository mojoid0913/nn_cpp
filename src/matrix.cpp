#include <iostream>
#include <vector>
#include <random>
#include "matrix.h"

using namespace std;

mt19937 gen(42);

Matrix::Matrix(int rows, int cols, InitType type) {
	this->rows = rows;
	this->cols = cols;
	this->size = rows * cols;
	vec.resize(size, 0.0);

	switch (type) {
		case ZERO:
			break;
		case RANDOM: {
			uniform_real_distribution<double> d(-0.1, 0.1);
			for(int i=0;i<size;i++) vec[i] = d(gen);
			break;
		}
		case LECUN: {
			double a = sqrt(3.0 / cols);
			uniform_real_distribution<double> d(-a, a);
			for(int i=0; i<size; i++) vec[i] = d(gen);
			break;
		}
		case XAVIER: {
			double a = sqrt(6.0 / (rows + cols));
			uniform_real_distribution<double> d(-a, a);
			for(int i=0; i<size; i++) vec[i] = d(gen);
			break;
		}
		case HE: {
			normal_distribution<double> d(0, sqrt(2.0 / cols));
			for(int i=0; i<size; i++) vec[i] = d(gen);
			break;
		}
		default:
			break;
	}
	//stride 개념 필요. (transpose 효율을 위해)
}

Matrix Matrix::add(Matrix Mat) {
	Matrix result(this->rows,this->cols,ZERO);

	for (int i = 0; i < this->size; i++)
		result.vec[i] = Mat.vec[i] + vec[i];

	return result; 
}

Matrix Matrix::multiply(Matrix Mat) {
	if (Mat.rows != this->cols) throw invalid_argument("Matrix size mismatch");
	Matrix result(this->rows, Mat.cols, ZERO);

	for (int i = 0; i < this->size; i++)
    for (int k = 0; k < this->cols; k++)
        result.vec[i] += vec[i/cols * cols + k] * Mat.vec[k * Mat.cols + i%Mat.cols];

	return result;
}

Matrix Matrix::transpose() {
	Matrix temp(cols,rows,ZERO);
	for (int i=0; i < this->rows; i++) {
		for (int j=0; j < this->cols; j++) {
			temp.vec[j*rows+i] = vec[i*cols+j];
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
