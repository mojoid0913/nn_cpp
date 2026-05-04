#pragma once
#include "matrix.h"
#include <cmath>

double cross_entropy(Matrix y_hat, Matrix y);
Matrix cross_entropy_backward(Matrix y_hat, Matrix y);
