#include "src/matrix.h"
#include "src/activations.h"
#include "src/layer.h"
#include <iostream>

int main() {
	Layer l1(3, 2, HE);
	Matrix input(3, 1, RANDOM);

	std::cout << "=== Forward ===\n";
	Matrix output = l1.forward(input);
	output.print();

	std::cout << "\n=== Backward ===\n";
	Matrix grad(2, 1, RANDOM);
	Matrix d_input = l1.backward(grad);
	d_input.print();

	std::cout << "\n=== dW ===\n";
	l1.dW.print();

	std::cout << "\n=== db ===\n";
	l1.db.print();

	return 0;
}
