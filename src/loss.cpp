#include "loss.h"

double cross_entropy(Matrix y_hat, Matrix y) {
	double L = 0;
	for(int i=0; i<y_hat.getSize(); i++)
			L += y.vec[i] * log(y_hat.vec[i]);
	return -L;
}

Matrix cross_entropy_backward(Matrix y_hat, Matrix y) {
	Matrix result(y_hat.getRows(), y_hat.getCols(), ZERO);
	for(int i=0; i<y_hat.getSize(); i++)
		result.vec[i] = y_hat.vec[i] - y.vec[i];
	return result;
}
