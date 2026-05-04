#pragma once
#include "matrix.h"

struct Layer {
	Matrix W;
	Matrix b;
	int input_size;
	int output_size;
	
	Layer(int input_size, int output_size, InitType init = HE);
	Matrix forward(Matrix intput);
	Matrix backward(Matrix gradient);
};
