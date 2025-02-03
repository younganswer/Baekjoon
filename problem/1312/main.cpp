#include <iostream>

int A, B, N;

int init() {
	std::cin >> A >> B >> N;
	return (0);
}

int solve() {
	while (N--) {
		A = (A % B) * 10;
	}
	std::cout << A / B << std::endl;
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
