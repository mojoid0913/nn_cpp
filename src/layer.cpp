#include "layer.h"
#include "matrix.h"

Layer::Layer(int input_size, int output_size, InitType type) {
		this->input_size = input_size;
		this->output_size = output_size;
		W = Matrix(output_size, input_size, type);
		b = Matrix(output_size, 1, ZERO);
}

Matrix Layer::forward(Matrix input) {
	last_input=input;
	return W.multiply(input).add(b);
}

Matrix Layer::backward(Matrix grad_mat) {
	dW = grad_mat.multiply(last_input.transpose());
	db = grad_mat;
	return W.transpose().multiply(grad_mat);
}
