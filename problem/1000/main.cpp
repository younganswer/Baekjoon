#include <iostream>

int a, b;

int init() {
	std::cin >> a >> b;
	return (0);
}

int solve() {
	std::cout << a + b << std::endl;
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (init() != 0) {
		return (-1);
	}

	if (solve() != 0) {
		return (-1);
	}

	return (0);
}
