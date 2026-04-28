#include "src/matrix.h"
#include <iostream>

int main() {
	Matrix W(5,2);

	W.print();
	std::cout << "\n";

	W = W.transpose();
	std::cout << "\n";
	W.print();
}
