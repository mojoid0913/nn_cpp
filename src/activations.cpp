#include "matrix.h"
#include "activations.h"
#include <cmath>

Matrix relu(Matrix mat) {
	Matrix result(mat.getRows(), mat.getCols(), true);
	for(int i=0; i<mat.getSize(); i++) {
		double val = mat.get(i);
		result.set(i, val > 0 ? val : 0.0);
	}
	return result;
}

Matrix relu_backward(Matrix mat) {
	Matrix result(mat.getRows(), mat.getCols(), true);
	for(int i=0; i<mat.getSize(); i++) {
		double val = mat.get(i);
		result.set(i, val > 0 ? 1.0 : 0.0);
	}
	return result;
}

Matrix sigmoid(Matrix mat) {
	Matrix result(mat.getRows(), mat.getCols(), true);
	for(int i=0; i<mat.getSize(); i++) {
		double s = 1.0 / (1.0 + exp(-1 * mat.get(i)));
		result.set(i, s);
	}
	return result;
}

Matrix sigmoid_backward(Matrix sigmoid_mat) {
	Matrix result(sigmoid_mat.getRows(), sigmoid_mat.getCols(), true);
	for(int i=0; i<sigmoid_mat.getSize(); i++) {
		double s = sigmoid_mat.get(i);
		result.set(i, s * (1 - s));
	}
	return result;
}
