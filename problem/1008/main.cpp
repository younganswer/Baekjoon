#include <iostream>
#include <iomanip>

int	main(void) {
	double A, B;

	std::cin >> A >> B;

	std::cout << std::fixed << std::setprecision(9);
	std::cout << A / B << std::endl;
	
	return (0);
}