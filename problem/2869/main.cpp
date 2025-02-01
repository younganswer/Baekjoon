#include <iostream>

int main(void) {
	int A, B, V;

	std::cin >> A >> B >> V;
	if ((V - A) % (A - B) == 0) {
		std::cout << ((V - A) / (A - B)) + 1 << std::endl;
	} else {
		std::cout << ((V - A) / (A - B)) + 2 << std::endl;
	}

	return (0);
}