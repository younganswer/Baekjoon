#include <iostream>
#include <string>

int	main(void) {
	std::string	str;

	int words = 0;
	while (std::cin >> str) {
		words++;
	}
	std::cout << words << std::endl;

	return (0);
}