#pragma once
#include "matrix.h"

struct Layer {
private:
	int input_size;
	int output_size;
	Matrix last_input;
public:
	Matrix W;
	Matrix b;
	Matrix dW;
	Matrix db;
	
	int getInputSize() { return input_size; };
	int getOutputSize() { return output_size; };

	Layer(int input_size, int output_size, InitType init = HE);
	Matrix forward(Matrix input);
	Matrix backward(Matrix gradient);
};
