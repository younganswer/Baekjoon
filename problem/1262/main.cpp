#include <iostream>

#define SUCCESS 0
#define FAILURE 0
#define MAX 20000

int N, R1, C1, R2, C2;

int init() {
	std::cin >> N >> R1 >> C1 >> R2 >> C2;

	return (0);
}

int solve() {
	for (int r = R1; r <= R2; r++) {
		for (int c = C1; c <= C2; c++) {
			int i = r % (2 * N - 1);
			int j = c % (2 * N - 1);

			if (i + j < N - 1 || 3 * (N - 1) < i + j || i - j < 1 - N || N - 1 < i - j) {
				std::cout << '.';
			} else {
				std::cout << (char) ('a' + (std::abs(i - (N - 1)) + std::abs(j - (N - 1))) % 26);
			}
		}
		std::cout << std::endl;
	}

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
