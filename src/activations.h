#pragma once
#include "matrix.h"

Matrix relu(Matrix mat);
Matrix relu_backward(Matrix mat);
Matrix sigmoid(Matrix mat);
Matrix sigmoid_backward(Matrix mat);
