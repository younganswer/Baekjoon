#include <iostream>
#include <string>

int	main(void) {
	int	A, B, C;

	std::cin >> A >> B >> C;

	std::cout << A + B - C << std::endl;
	std::cout << std::stoi(std::to_string(A) + std::to_string(B)) - C << std::endl;

	return (0);
}