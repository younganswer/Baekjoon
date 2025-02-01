#include <iostream>
#include <string>

std::string	itofizzbuzz(int num);

int	main(void) {
	std::string	strs[3];

	std::cin >> strs[0] >> strs[1] >> strs[2];
	for (int i=0; i<3; i++) {
		try {
			int num = std::stoi(strs[i]);
			std::cout << itofizzbuzz(num + 3 - (i % 3)) << std::endl;
			return (0);
		} catch (const std::exception &e) {
			;
		}
	}
	return (0);
}

std::string	itofizzbuzz(int num) {
	if ((num % 3) == 0 && (num % 5) == 0) {
		return std::string("FizzBuzz");
	}
	if ((num % 3) == 0) {
		return std::string("Fizz");
	}
	if ((num % 5) == 0) {
		return std::string("Buzz");
	}
	return std::to_string(num);
}