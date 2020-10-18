#include "Matrix.hpp"

int	main(void)
{
	Matrix A(2, 2);
	Matrix B(3, 3);

	A.setEntry(0, 0, 2);
	A.setEntry(0, 1, 6);
	A.setEntry(1, 0, 3);
	A.setEntry(1, 1, -1);
	B.setEntry(0, 0, -4);
	B.setEntry(0, 1, -2);
	B.setEntry(0, 2, 5);
	B.setEntry(1, 0, 1);
	B.setEntry(1, 1, 0);
	B.setEntry(1, 2, -7);
	A.print();
	std::cout << "\n";
	B.print();
	std::cout << "\nproduct:\n";
	A.multiply(B).print();

}
