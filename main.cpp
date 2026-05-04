#include "src/matrix.h"
#include "src/activations.h"
#include <iostream>

int main() {
	Matrix W(5,2);

	W.print();
	std::cout << "\n";

	Matrix S = sigmoid(W);
	S.print();
	std::cout << "\n";

	Matrix S_back = sigmoid_backward(S);
	S_back.print();
}
